function doGet(e) { 
  Logger.log(JSON.stringify(e));
  var result = 'Ok';
  /*if (e.parameter == 'undefined') {
    result = 'No Parameters';
  }
  else*/ {
    var sheet_id = 'SHEET_ID';  // Spreadsheet ID.
    var sheet_name = "SHEET_NAME";  // Sheet Name in Google Sheets.

    var sheet_open = SpreadsheetApp.openById(sheet_id);
    var sheet_target = sheet_open.getSheetByName(sheet_name);
var sheet_target2 = sheet_open.getSheetByName("Sheet_NAME2");

    var newRow = sheet_target.getLastRow() + 1;

    var rowDataLog = [5];

    var Data_for_I3;
    var Data_for_J3;
    var Data_for_K3;
    var Data_for_L3;
    var Data_for_M3;
    var Data_for_N3;
    var Data_for_O3;

    var Curr_Date = Utilities.formatDate(new Date(), "GMT+5:30", 'dd/MM/yyyy');
    rowDataLog[0] = Curr_Date;  // Date will be written in column A.
    Data_for_I3 = Curr_Date;  // Date will be written in column I3.

    var Curr_Time = Utilities.formatDate(new Date(), "GMT+5:30", 'HH:mm:ss');
    rowDataLog[1] = Curr_Time;  // Time will be written in column B.
    Data_for_J3 = Curr_Time;  // Time will be written in column J3.

    var sts_val = '';

    for (var param in e.parameter) {
      Logger.log('In for loop, param=' + param);
      var value = stripQuotes(e.parameter[param]);
      Logger.log(param + ':' + e.parameter[param]);
      switch (param) {
        case 'sts':
          sts_val = value;
          break;

        case 'srs':
          rowDataLog[2] = value;  // Sensor Reading Status will be written in column C.
          Data_for_K3 = value;  // Sensor Reading Status will be written in column K3.
          /*if(value=="relay"){rowDataLog[3] = 1; rowDataLog[4] = 0;} // The temperature value will be written in column D.
          if(value=="resistor"){rowDataLog[3] = 2; rowDataLog[4] = 1;}
          if(value=="capacitor"){rowDataLog[3] = 3; rowDataLog[4] = 0;}
          if(value=="inductor"){rowDataLog[3] = 3; rowDataLog[4] = 0;}*/
          result += ', Sensor Reading Status Written on column C';
          break;

        /*case 'temp':
        rowDataLog[2] = value;
          
          Data_for_L3 = value;  // The temperature value will be written in column L3.
          result += ', Temperature Written on column D';
          break;

        case 'humd':
          rowDataLog[4] = value; // The humidity value will be written in column E.
          Data_for_M3 = value;  // The humidity value will be written in column M3.
          result += ', Humidity Written on column E';
          break;

        case 'swtc1':
          rowDataLog[5] = value;  // The state of Switch_1 will be written in column F.
          Data_for_N3 = value;  // The state of Switch_1 will be written in column N3.
          result += ', Switch_1 Written on column F';
          break;

        case 'swtc2':
          rowDataLog[6] = value;  // The state of Switch_2 will be written in column G.
          Data_for_O3 = value;  // The state of Switch_2 will be written in column O3.
          result += ', Switch_2 Written on column G';
          break;  */

        default:
          result += ", unsupported parameter";
      }
    }
    
    // Conditions for writing data received from ESP32 to Google Sheets.
    if (sts_val == 'write') {
      // Writes data website
      Logger.log(JSON.stringify(rowDataLog));
      var newRangeDataLog = sheet_target.getRange(newRow, 1, 1, rowDataLog.length);
      newRangeDataLog.setValues([rowDataLog]);
      return ContentService.createTextOutput(rowDataLog);
    }

    if (sts_val == 'write2') {
    var source = sheet_target.getRange(3,1,1,7);
    // after deliver of goods
    var destination = sheet_target2.getRange(sheet_target2.getLastRow()+1,1,1,7);
    // copy values to destination range
    source.copyTo(destination);
    var cell = sheet_target2.getRange(sheet_target2.getLastRow(),8);
    cell.setValue(Curr_Time);
    // clear source values
    //source.clearContent();
    sheet_target.deleteRow(3); 
    //return ContentService.createTextOutput(source);
    }
    
    // Conditions for sending data to ESP32 when ESP32 reads data from Google Sheets.
    if (sts_val == 'read') {//microcontroller read
      var all_Data = sheet_target.getRange('C3:E3').getValues();
      return ContentService.createTextOutput(JSON.stringify(all_Data[0])); // Ensure data is returned as JSON string
    }
    
    // Handle deletion request
    /*if (sts_val == 'delete') {
      var sheet_target2 = sheet_open.getSheetByName("Sheet2");
    //var range = sheet_target2.getRange("A3:G3");
      //range.deleteCells(SpreadsheetApp.Dimension.COLUMNS);
      sheet_target.deleteRow(3); 
    }*/
  }
}

function stripQuotes(value) {
  return value.replace(/^["']|['"]$/g, "");
}

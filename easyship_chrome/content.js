chrome.runtime.sendMessage({todo : "showPageAction"});
chrome.runtime.onMessage.addListener(function(request,sender,sendResponse){

if(request.todo == "GetSummary")
{
    console.log("dadada");
    jsonObj = [];
    var val = $("span.courier-title-one").text();
    jsonObj.push(val);
    console.log(jsonObj);
    $.ajax({
        type : 'POST',
        url : "http://127.0.0.1:5000/",
        //contentType: 'application/json;charset=UTF-8',
        contentType: 'application/json',
        data : JSON.stringify(jsonObj),
        dataType:"json",
        crossDomain: true,
        success : function(response){ 
            console.log("Respose reached");
            console.log(response); 
        },
        error : function(response)
        {
            console.log("Error");
            console.log(response);
        }
    });

}
});
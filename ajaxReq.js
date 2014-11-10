/***************************************************************************
ajaxReq.js

A client-side ajax module.
****************************************************************************/

/*----------------------------------------------------
getXMLHttpReq
getXMLHttpReq()

DESCRIPTION: Standard function for getting a getXMLHttpReq object
Returns the object (or null if an object couldn't be created)
----------------------------------------------------*/
function getXMLHttpReq()
{ var req = null;

if (window.XMLHttpRequest)
   req = new XMLHttpRequest();
else if (window.ActiveXObject)
   req = new ActiveXObject(Microsoft.XMLHTTP);
return req;
}

/*----------------------------------------------------
ajaxRequestPost
ajaxRequestPost(urlStr, dataStr, contentType, asynch, extra,
                                                 goodFunction, badFunction)

DESCRIPTION: Does AJAX post request, and calls functions sent as parameters to 
handle the results.  The parameters are:

   urlStr: URL of the server-side script to be called
   dataStr: Data string sent to the server-side script
   contentType: Provides the content type of the data sent
   asynch: if true sends an asynchronous request
   successExtra: Extra param that can be used by call back function called when
                 there is not a server error.  It can be useful for using the 
                 same callback function for different calls.  Just pass a dummy 
                 value in if not needed and then don't use it in the callback.
   servErrExtra: Extra param that can be used by call back function called 
                 when there is a server error.  It can be useful for using the 
                 same callback function for different calls.  Just pass a dummy 
                 value in if not needed and then don't use it in the callback.
   successFunc: Function to call on success.  It takes one parameter, the
                 responseText
   servErrFunc: Function to call on error.  It takes two parameters: the
                 request status and the request statusText
   
RETURNS: false on failure and true on success
----------------------------------------------------*/
function ajaxRequestPost(urlStr, dataStr, contentType, asynch, successExtra,
                                        servErrExtra, successFunc, servErrFunc)
{ var req = getXMLHttpReq();

if (req == null)
   return false;

req.open("POST", urlStr, asynch);
req.onreadystatechange = function()
   {
   if(req.readyState == 4)
      {
      if(req.status == 200)
         successFunc(req.responseText, successExtra);
      else
         servErrFunc(req.status, req.statusText, servErrExtra);
      }
   }
req.setRequestHeader("Content-Type", contentType);
req.send(dataStr);
return true;
}


/*----------------------------------------------------
ajaxRequestGet
ajaxRequestGet(urlStr, dataStr, asynch, extra, goodFunction, badFunction)

DESCRIPTION: Does AJAX get request, and calls functions sent as parameters to 
handle the results.  The variable dataStr should be URL encoded.
The parameters are:

   urlStr: URL of the server-side script to be called
   dataStr: Data string sent to the server-side script
   contentType: Provides the content type of the data sent
   asynch: if true sends an asynchronous request
   successExtra: Extra param that can be used by call back function called when
                 there is not a server error.  It can be useful for using the 
                 same callback function for different calls.  Just pass a dummy 
                 value in if not needed and then don't use it in the callback.
   servErrExtra: Extra param that can be used by call back function called 
                 when there is a server error.  It can be useful for using the 
                 same callback function for different calls.  Just pass a dummy 
                 value in if not needed and then don't use it in the callback.
   successFunc: Function to call on success.  It takes one parameter, the
                 responseText
   servErrFunc: Function to call on error.  It takes two parameters: the
                 request status and the request statusText
   
RETURNS: 0
----------------------------------------------------*/
function ajaxRequestGet(urlStr, dataStr, asynch, successExtra, servErrExtra,
                                                     successFunc, servErrFunc)
{ var req = getXMLHttpReq();

if (req == null)
   return false;

urlStr += "?" + dataStr;
req.open("GET", urlStr, asynch);

req.onreadystatechange = function()
   {
   if(req.readyState == 4)
      {
      if(req.status == 200)
         successFunc(req.responseText, successExtra);
      else
         servErrFunc(req.status, req.statusText, servErrExtra);
      }
   }
req.send(null);
return 0;
}
/*
 * =============================================================================
 *
 *       Filename:  copy_object.cc
 *
 *    Description:  copy_object example.
 *
 *        Created:  09/21/2012 09:21:49 AM
 *
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/**
* 拷贝一个在OSS上已经存在的Object成另外一个Object
*/
#include <osscpp/client.h>
#include <iostream>
#include <string>

using namespace std;
using namespace osscpp;

static const string access_id  = "ACSGmv8fkV1TDO9L"; /**设置用户 Access ID */
static const string access_key = "BedoWbsJe2"; /** 设置用户的 Access Key */
static const string endpoint   = "storage.aliyun.com";    //设置 hostname

int main()
{
	OSS_ERROR_CODE retcode;			//保存服务器http返回码的解析结果;

	Client client(access_id, access_key, endpoint);
	const string source_bucket_name = "bucketname001";       //设置bucket_name
	const string destination_bucket_name = "bucketexample03";       //设置bucket_name
	const string source_key = "glib-2.32.4.tar.xz"; 
	const string destination_key = "copy-of-glib-2.32.4.tar.xz"; 

	CopyObjectRequest request(source_bucket_name, source_key,
			destination_bucket_name, destination_key);
	CopyObjectResult result;
	result = client.CopyObject(request, retcode);
	if(retcode == 0) {
		cout << "copy object successfully." << endl;
		cout << "Last Modified: " << result.last_modified() << endl;
		cout << "ETAG: " << result.etag() << endl;
	} else {
		cout << "failed to copy object" << endl;
		cout << Util::GetMessageFromRetcode(retcode) << endl;
	}

	return 0;
}


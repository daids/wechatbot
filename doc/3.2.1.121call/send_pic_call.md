6863CB6F     | 83EC 14           | sub esp,14                           | ·¢ËÍpic call
6863CB72     | 8D47 E0           | lea eax,dword ptr ds:[edi-20]        |
6863CB75     | 8BCC              | mov ecx,esp                          |
6863CB77     | 8965 BC           | mov dword ptr ss:[ebp-44],esp        |
6863CB7A     | 50                | push eax                             |
6863CB7B     | E8 60FE4700       | call wechatwin.68ABC9E0              |
6863CB80     | 53                | push ebx                             | ebx:&L"C:\\tmp\\2.jpg"
6863CB81     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        | [ebp-88]:L"23023281066@chatroom"
6863CB87     | C645 FC 09        | mov byte ptr ss:[ebp-4],9            | 9:'\t'
6863CB8B     | 50                | push eax                             |
6863CB8C     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
6863CB92     | 50                | push eax                             |
6863CB93     | E8 886BF5FF       | call wechatwin.68593720              |
6863CB98     | 8BC8              | mov ecx,eax                          |
6863CB9A     | C645 FC 01        | mov byte ptr ss:[ebp-4],1            |
6863CB9E     | E8 BD832A00       | call wechatwin.688E4F60              |
6863CBA3     | C645 FC 0A        | mov byte ptr ss:[ebp-4],A            | A:'\n'
6863CBA7     | E8 D4EA1D00       | call wechatwin.6881B680              |
6863CBAC     | 8BC8              | mov ecx,eax                          |
6863CBAE     | E8 7DA63F00       | call wechatwin.68A37230              |
6863CBB3     | 8D8D B0FCFFFF     | lea ecx,dword ptr ss:[ebp-350]       |
6863CBB9     | 8955 BC           | mov dword ptr ss:[ebp-44],edx        |
6863CBBC     | 8BF8              | mov edi,eax                          |
6863CBBE     | E8 6DA63F00       | call wechatwin.68A37230              |
6863CBC3     | 3BC7              | cmp eax,edi                          |
6863CBC5     | 75 43             | jne wechatwin.6863CC0A               |
6863CBC7     | 3B55 BC           | cmp edx,dword ptr ss:[ebp-44]        |
6863CBCA     | 75 3E             | jne wechatwin.6863CC0A               |
6863CBCC     | E8 AF6BF5FF       | call wechatwin.68593780              |


68ABC9E0-68530000=58C9E0
68593720-68530000=63720
688E4F60-68530000=3B4F60


Base=68530000
Module=wechatwin.dll
Party=User
Path=C:\Program Files (x86)\Tencent\WeChat\WeChatWin.dll
Status=Unloaded

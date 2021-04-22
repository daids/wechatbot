6863CCB0     | 884D 94           | mov byte ptr ss:[ebp-6C],cl          | 【3.2.1.121】发送附件call开头
6863CCB3     | 8D47 E0           | lea eax,dword ptr ds:[edi-20]        |
6863CCB6     | 8BCC              | mov ecx,esp                          |
6863CCB8     | 8965 BC           | mov dword ptr ss:[ebp-44],esp        |
6863CCBB     | 50                | push eax                             |
6863CCBC     | E8 1FFD4700       | call wechatwin.68ABC9E0              |
6863CCC1     | FF75 94           | push dword ptr ss:[ebp-6C]           | 【3.2.1.121】发送附件call
6863CCC4     | 83EC 14           | sub esp,14                           |
6863CCC7     | 8BCC              | mov ecx,esp                          |
6863CCC9     | 8965 90           | mov dword ptr ss:[ebp-70],esp        |
6863CCCC     | 6A FF             | push FFFFFFFF                        |
6863CCCE     | 68 C8B9D069       | push wechatwin.69D0B9C8              |
6863CCD3     | E8 C8FC4700       | call wechatwin.68ABC9A0              |
6863CCD8     | 83EC 14           | sub esp,14                           |
6863CCDB     | 8BCC              | mov ecx,esp                          |
6863CCDD     | 8965 8C           | mov dword ptr ss:[ebp-74],esp        |
6863CCE0     | 53                | push ebx                             |
6863CCE1     | E8 FAFC4700       | call wechatwin.68ABC9E0              |
6863CCE6     | 83EC 14           | sub esp,14                           |
6863CCE9     | 8D85 78FFFFFF     | lea eax,dword ptr ss:[ebp-88]        |
6863CCEF     | 8BCC              | mov ecx,esp                          |
6863CCF1     | 8965 B0           | mov dword ptr ss:[ebp-50],esp        |
6863CCF4     | 50                | push eax                             |
6863CCF5     | E8 E6FC4700       | call wechatwin.68ABC9E0              |
6863CCFA     | 8D85 B0FCFFFF     | lea eax,dword ptr ss:[ebp-350]       |
6863CD00     | C645 FC 10        | mov byte ptr ss:[ebp-4],10           |
6863CD04     | 50                | push eax                             |
6863CD05     | E8 36BDF5FF       | call wechatwin.68598A40              |
6863CD0A     | 8BC8              | mov ecx,eax                          |
6863CD0C     | C645 FC 0C        | mov byte ptr ss:[ebp-4],C            | C:'\f'
6863CD10     | E8 CB3E1B00       | call wechatwin.687F0BE0              |
6863CD15     | C645 FC 11        | mov byte ptr ss:[ebp-4],11           |
6863CD19     | E8 62E91D00       | call wechatwin.6881B680              |
6863CD1E     | 8BC8              | mov ecx,eax                          |
6863CD20     | E8 0BA53F00       | call wechatwin.68A37230              |
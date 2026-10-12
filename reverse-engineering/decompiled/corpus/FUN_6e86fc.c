/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e86fc; label: FUN_006e86fc
 */

uint FUN_006e86fc(undefined1 *param_1,size_t param_2,uint param_3,uint param_4,FILE *param_5)

{
  uint uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint local_10;
  
  if ((param_3 != 0) && (param_4 != 0)) {
    if (param_1 != (undefined1 *)0x0) {
      if ((param_5 != (FILE *)0x0) && (param_4 <= (uint)(0xffffffff / (ulonglong)param_3))) {
LAB_006e8775:
        uVar8 = param_3 * param_4;
        uVar7 = uVar8;
        puVar2 = param_1;
        uVar1 = param_2;
        if ((param_5->_flag & 0x10c) == 0) {
          local_10 = 0x1000;
        }
        else {
          local_10 = param_5->_bufsiz;
        }
joined_r0x006e879a:
        do {
          while( true ) {
            if (uVar7 == 0) {
              return param_4;
            }
            if ((param_5->_flag & 0x10c) == 0) break;
            uVar4 = param_5->_cnt;
            if (uVar4 == 0) break;
            if ((int)uVar4 < 0) {
LAB_006e88ea:
              param_5->_flag = param_5->_flag | 0x20;
LAB_006e88ee:
              return (uVar8 - uVar7) / param_3;
            }
            uVar6 = uVar7;
            if (uVar4 <= uVar7) {
              uVar6 = uVar4;
            }
            if (uVar1 < uVar6) {
              if (param_2 != 0xffffffff) {
                _memset(param_1,0,param_2);
              }
              puVar3 = (undefined4 *)FUN_006ead5f();
              *puVar3 = 0x22;
              goto LAB_006e8731;
            }
            _memcpy_s(puVar2,uVar1,param_5->_ptr,uVar6);
            param_5->_cnt = param_5->_cnt - uVar6;
            param_5->_ptr = param_5->_ptr + uVar6;
            uVar7 = uVar7 - uVar6;
            uVar1 = uVar1 - uVar6;
            puVar2 = puVar2 + uVar6;
          }
          if (local_10 <= uVar7) {
            if (local_10 == 0) {
              uVar4 = 0x7fffffff;
              if (uVar7 < 0x80000000) {
                uVar4 = uVar7;
              }
            }
            else {
              if (uVar7 < 0x80000000) {
                uVar6 = uVar7 % local_10;
                uVar4 = uVar7;
              }
              else {
                uVar6 = (uint)(0x7fffffff % (ulonglong)local_10);
                uVar4 = 0x7fffffff;
              }
              uVar4 = uVar4 - uVar6;
            }
            if (uVar1 < uVar4) {
LAB_006e88bd:
              if (param_2 != 0xffffffff) {
                _memset(param_1,0,param_2);
              }
              puVar3 = (undefined4 *)FUN_006ead5f();
              *puVar3 = 0x22;
              goto LAB_006e8731;
            }
            puVar9 = puVar2;
            iVar5 = __fileno(param_5);
            iVar5 = FUN_006f572b(iVar5,puVar9,uVar4);
            if (iVar5 == 0) {
              param_5->_flag = param_5->_flag | 0x10;
              goto LAB_006e88ee;
            }
            if (iVar5 == -1) goto LAB_006e88ea;
            uVar7 = uVar7 - iVar5;
            uVar1 = uVar1 - iVar5;
            puVar2 = puVar2 + iVar5;
            goto joined_r0x006e879a;
          }
          iVar5 = __filbuf(param_5);
          if (iVar5 == -1) goto LAB_006e88ee;
          if (uVar1 == 0) goto LAB_006e88bd;
          *puVar2 = (char)iVar5;
          local_10 = param_5->_bufsiz;
          uVar7 = uVar7 - 1;
          uVar1 = uVar1 - 1;
          puVar2 = puVar2 + 1;
        } while( true );
      }
      if (param_2 != 0xffffffff) {
        _memset(param_1,0,param_2);
      }
      if ((param_5 != (FILE *)0x0) && (param_4 <= (uint)(0xffffffff / (ulonglong)param_3)))
      goto LAB_006e8775;
    }
    puVar3 = (undefined4 *)FUN_006ead5f();
    *puVar3 = 0x16;
LAB_006e8731:
    FUN_006e9fc2(0,0,0,0,0);
  }
  return 0;
}


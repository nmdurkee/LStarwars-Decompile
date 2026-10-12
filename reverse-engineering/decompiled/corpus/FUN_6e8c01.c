/* Ghidra analysis pseudocode, not original source.
 * ev_5e4e6a590c471e22d2a814bcf9fd12a554b410855fef8706c3d4a3775c91fbe8
 * Entry: 0x6e8c01; label: FUN_006e8c01
 */

uint FUN_006e8c01(char *param_1,uint param_2,uint param_3,FILE *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint _Size;
  uint uVar5;
  uint uVar6;
  char *_Buf;
  uint local_c;
  char *local_8;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    if ((param_4 != (FILE *)0x0) &&
       ((param_1 != (char *)0x0 && (param_3 <= (uint)(0xffffffff / (ulonglong)param_2))))) {
      uVar6 = param_2 * param_3;
      uVar5 = uVar6;
      if ((param_4->_flag & 0x10c) == 0) {
        local_c = 0x1000;
      }
      else {
        local_c = param_4->_bufsiz;
      }
      do {
        while( true ) {
          if (uVar5 == 0) {
            return param_3;
          }
          uVar4 = param_4->_flag & 0x108;
          if (uVar4 == 0) break;
          uVar3 = param_4->_cnt;
          if (uVar3 == 0) break;
          if ((int)uVar3 < 0) {
            param_4->_flag = param_4->_flag | 0x20;
            goto LAB_006e8d4b;
          }
          _Size = uVar5;
          if (uVar3 <= uVar5) {
            _Size = uVar3;
          }
          _memcpy(param_4->_ptr,param_1,_Size);
          param_4->_cnt = param_4->_cnt - _Size;
          param_4->_ptr = param_4->_ptr + _Size;
          uVar5 = uVar5 - _Size;
LAB_006e8d07:
          local_8 = param_1 + _Size;
          param_1 = local_8;
        }
        if (local_c <= uVar5) {
          if ((uVar4 != 0) && (iVar2 = __flush(param_4), iVar2 != 0)) goto LAB_006e8d4b;
          uVar4 = uVar5;
          if (local_c != 0) {
            uVar4 = uVar5 - uVar5 % local_c;
          }
          _Buf = param_1;
          uVar3 = uVar4;
          iVar2 = __fileno(param_4);
          uVar3 = __write(iVar2,_Buf,uVar3);
          if (uVar3 != 0xffffffff) {
            _Size = uVar4;
            if (uVar3 <= uVar4) {
              _Size = uVar3;
            }
            uVar5 = uVar5 - _Size;
            if (uVar4 <= uVar3) goto LAB_006e8d07;
          }
          param_4->_flag = param_4->_flag | 0x20;
LAB_006e8d4b:
          return (uVar6 - uVar5) / param_2;
        }
        iVar2 = __flsbuf((int)*param_1,param_4);
        if (iVar2 == -1) goto LAB_006e8d4b;
        param_1 = param_1 + 1;
        local_c = param_4->_bufsiz;
        uVar5 = uVar5 - 1;
        if ((int)local_c < 1) {
          local_c = 1;
        }
      } while( true );
    }
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
  }
  return 0;
}


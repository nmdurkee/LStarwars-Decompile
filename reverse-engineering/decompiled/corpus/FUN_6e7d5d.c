/* Ghidra analysis pseudocode, not original source.
 * ev_eecf13eba2be62f78d2c2fac028dc2e8e01e29bc459957490b66b8c35bfd6df7
 * Entry: 0x6e7d5d; label: vfprintf_helper
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    _vfprintf_helper
   
   Library: Visual Studio 2005 Release */

int __cdecl
vfprintf_helper(code *param_1,FILE *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  int local_20;
  
  local_20 = 0;
  if ((param_2 == (FILE *)0x0) || (param_3 == 0)) {
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    return -1;
  }
  FUN_006e82ae(param_2);
  if ((param_2->_flag & 0x40) == 0) {
    iVar2 = __fileno(param_2);
    if ((iVar2 == -1) || (iVar2 = __fileno(param_2), iVar2 == -2)) {
      puVar4 = &DAT_00829c00;
    }
    else {
      iVar2 = __fileno(param_2);
      uVar3 = __fileno(param_2);
      puVar4 = (undefined *)((uVar3 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar2 >> 5]);
    }
    if ((puVar4[0x24] & 0x7f) == 0) {
      iVar2 = __fileno(param_2);
      if ((iVar2 == -1) || (iVar2 = __fileno(param_2), iVar2 == -2)) {
        puVar4 = &DAT_00829c00;
      }
      else {
        iVar2 = __fileno(param_2);
        uVar3 = __fileno(param_2);
        puVar4 = (undefined *)((uVar3 & 0x1f) * 0x38 + (&DAT_029a9b40)[iVar2 >> 5]);
      }
      if ((puVar4[0x24] & 0x80) == 0) goto LAB_006e7e65;
    }
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 0x16;
    FUN_006e9fc2(0,0,0,0,0);
    local_20 = -1;
  }
LAB_006e7e65:
  if (local_20 == 0) {
    iVar2 = __stbuf(param_2);
    local_20 = (*param_1)(param_2,param_3,param_4,param_5);
    __ftbuf(iVar2,param_2);
  }
  FUN_006e7ea1();
  return local_20;
}


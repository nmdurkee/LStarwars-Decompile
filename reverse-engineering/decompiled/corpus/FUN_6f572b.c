/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f572b; label: FUN_006f572b
 */

/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */

undefined4 FUN_006f572b(uint param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_20;
  
  if (param_1 == 0xfffffffe) {
    puVar1 = (undefined4 *)FUN_006ead72();
    *puVar1 = 0;
    puVar1 = (undefined4 *)FUN_006ead5f();
    *puVar1 = 9;
    return 0xffffffff;
  }
  if ((-1 < (int)param_1) && (param_1 < DAT_029a9b2c)) {
    iVar2 = (param_1 & 0x1f) * 0x38;
    if ((*(byte *)((&DAT_029a9b40)[(int)param_1 >> 5] + 4 + iVar2) & 1) != 0) {
      if (param_3 < 0x80000000) {
        ___lock_fhandle(param_1);
        if ((*(byte *)((&DAT_029a9b40)[(int)param_1 >> 5] + 4 + iVar2) & 1) == 0) {
          puVar1 = (undefined4 *)FUN_006ead5f();
          *puVar1 = 9;
          puVar1 = (undefined4 *)FUN_006ead72();
          *puVar1 = 0;
          local_20 = 0xffffffff;
        }
        else {
          local_20 = FUN_006f516a(param_1,param_2,param_3);
        }
        FUN_006f581e();
        return local_20;
      }
      puVar1 = (undefined4 *)FUN_006ead72();
      *puVar1 = 0;
      puVar1 = (undefined4 *)FUN_006ead5f();
      *puVar1 = 0x16;
      goto LAB_006f577a;
    }
  }
  puVar1 = (undefined4 *)FUN_006ead72();
  *puVar1 = 0;
  puVar1 = (undefined4 *)FUN_006ead5f();
  *puVar1 = 9;
LAB_006f577a:
  FUN_006e9fc2(0,0,0,0,0);
  return 0xffffffff;
}


/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4fecf0; label: FUN_004fecf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004fecf0(undefined4 param_1,undefined4 param_2,void *param_3,size_t param_4)

{
  undefined4 *puVar1;
  void *extraout_ECX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
  puVar1 = (undefined4 *)FUN_00547240(DAT_0091f1b4);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = puVar1[2] & 0xfffffffc;
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[0x44] = 0;
    puVar1[0x45] = 0;
    if ((param_3 != (void *)0x0) && (param_4 != 0)) {
      if (0x100 < (int)param_4) {
        param_4 = FUN_004fe640(0x100);
        param_3 = extraout_ECX;
      }
      _memcpy(puVar1 + 4,param_3,param_4);
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_009211e8);
  if (puVar1 != (undefined4 *)0x0) {
    SetEvent(DAT_0091f1a8);
  }
  return puVar1;
}


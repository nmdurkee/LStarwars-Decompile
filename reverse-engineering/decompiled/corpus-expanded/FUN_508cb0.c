/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x508cb0; label: FUN_00508cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00508cb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  
  DAT_00921350 = DAT_00921350 + 1;
  if (0xff < DAT_00921350) {
    DAT_00921350 = 1;
  }
  _DAT_00921370 = 0;
  _DAT_00921374 = 0;
  DAT_0092137c = 0;
  _DAT_0092136c = 0;
  puVar1 = DAT_0092133c;
  if (param_1 != 0) {
    param_2 = 0;
  }
  for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((int)(puVar1[0x22] << 5) >> 0x18 != DAT_00921350) {
      FUN_00508340(puVar1,param_1,param_2,param_3);
    }
  }
  return;
}


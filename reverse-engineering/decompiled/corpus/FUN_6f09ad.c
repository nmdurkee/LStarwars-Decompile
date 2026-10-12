/* Ghidra analysis pseudocode, not original source.
 * ev_526838828e273a637259fe0c0b8910ed57fcbb113f7ca97b4fe0b36ecb2b0c42
 * Entry: 0x6f09ad; label: FUN_006f09ad
 */

undefined4 FUN_006f09ad(int *param_1)

{
  undefined *puVar1;
  
  param_1 = (int *)*param_1;
  if (((*param_1 == -0x1f928c9d) && (param_1[4] == 3)) &&
     ((puVar1 = (undefined *)param_1[5], puVar1 == (undefined *)0x19930520 ||
      (((puVar1 == (undefined *)0x19930521 || (puVar1 == (undefined *)0x19930522)) ||
       (puVar1 == &DAT_01994000)))))) {
    terminate();
  }
  return 0;
}


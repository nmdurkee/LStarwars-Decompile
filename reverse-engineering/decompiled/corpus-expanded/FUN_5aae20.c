/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5aae20; label: FUN_005aae20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005aae20(int *param_1,uint param_2)

{
  int iVar1;
  
  if ((((param_1 != (int *)0x0) && (iVar1 = *param_1, iVar1 != 0)) && (param_2 < 8)) &&
     ((float)(int)*(char *)(iVar1 + 0x2c + param_2) == *(float *)(iVar1 + 0x28))) {
    return 1;
  }
  return 0;
}


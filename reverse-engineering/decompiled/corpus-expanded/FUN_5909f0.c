/* Ghidra pseudocode, not original source.
 * ev_d7fef5854a4ea50d405948ed3aa82c9004ffbc8626dda7a7f3cbba7e59036064
 * Entry: 0x5909f0; label: FUN_005909f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005909f0(int *param_1,undefined4 param_2,int param_3)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(*param_1 + 0x7a);
  if (((((uVar1 & 2) != 0) && ((uVar1 & 1) != 0)) || (param_3 != 0)) &&
     (*(char *)(*param_1 + 0x6d) == '\x02')) {
    return 1;
  }
  return 0;
}


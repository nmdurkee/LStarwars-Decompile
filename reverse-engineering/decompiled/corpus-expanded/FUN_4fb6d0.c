/* Ghidra pseudocode, not original source.
 * ev_a3914b5cac229e7918c10cf8a5346a655cb71c58f8911b074eca1b5c8824e452
 * Entry: 0x4fb6d0; label: FUN_004fb6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004fb6d0(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((((DAT_00800474 != 0) && (*(int *)(&DAT_008ceb40 + param_1 * 0x40) != 0)) &&
      ((param_3 & 0x7ff) == 0)) && ((param_4 & 0x7ff) == 0)) {
    return 0;
  }
  FUN_004f6de0(param_1,param_4,(int)param_4 >> 0x1f,0);
  uVar1 = FUN_004fb550(param_1,param_2,param_3);
  return uVar1;
}


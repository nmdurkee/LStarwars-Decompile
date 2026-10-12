/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1500; label: FUN_004f1500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1500(uint param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 < 4) {
    param_1 = 4;
  }
  uVar1 = param_1 + param_3 & ~param_3;
  param_4[1] = uVar1;
  param_4[2] = param_2;
  *(short *)((int)param_4 + 0xe) = (short)param_2;
  *(undefined2 *)(param_4 + 3) = 1;
  if (param_2 == 0) {
    *param_4 = 0;
    return;
  }
  param_2 = param_2 + -1;
  puVar3 = (undefined4 *)((param_3 + 0x10 & ~param_3) + (int)param_4);
  *param_4 = puVar3;
  puVar2 = puVar3;
  if (0 < param_2) {
    do {
      param_2 = param_2 + -1;
      puVar3 = (undefined4 *)((int)puVar2 + (uVar1 & 0xfffffffc));
      *puVar2 = puVar3;
      puVar2 = puVar3;
    } while (param_2 != 0);
  }
  *puVar3 = 0;
  return;
}


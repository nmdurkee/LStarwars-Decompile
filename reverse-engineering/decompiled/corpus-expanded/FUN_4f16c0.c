/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f16c0; label: FUN_004f16c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f16c0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)(param_1 + -0x10);
  do {
    puVar1 = DAT_0091eec8;
    if ((puVar1 < puVar2) && (puVar2 < (uint *)*puVar1)) break;
    DAT_0091eec8 = (uint *)*puVar1;
  } while ((puVar1 < DAT_0091eec8) || ((puVar2 <= puVar1 && (DAT_0091eec8 <= puVar2))));
  puVar3 = (uint *)*puVar1;
  if (puVar2 + *(int *)(param_1 + -0xc) * 4 == puVar3) {
    *(uint *)(param_1 + -0xc) = puVar3[1] + *(int *)(param_1 + -0xc);
    puVar3 = *(uint **)*puVar1;
  }
  *puVar2 = (uint)puVar3;
  DAT_0091eec8 = puVar1;
  if (puVar1 + puVar1[1] * 4 == puVar2) {
    puVar1[1] = *(int *)(param_1 + -0xc) + puVar1[1];
    puVar2 = (uint *)*puVar2;
  }
  *puVar1 = (uint)puVar2;
  return;
}


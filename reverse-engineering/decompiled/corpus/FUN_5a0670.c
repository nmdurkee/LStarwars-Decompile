/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0670; label: FUN_005a0670
 */

void FUN_005a0670(float param_1)

{
  undefined4 *puVar1;
  float fVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  
  iVar5 = (int)param_1;
  bVar3 = true;
  bVar4 = true;
  if ((*(byte *)((int)param_1 + 10) & 4) == 0) {
    for (puVar1 = *(undefined4 **)((int)param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[4] != 0) {
        if ((float)puVar1[6] <= (float)puVar1[7]) {
          param_1 = 1.0;
        }
        else {
          param_1 = -1.0;
        }
        fVar2 = param_1 * *(float *)(puVar1[4] + 0x4c);
        if (fVar2 < (float)puVar1[7] * param_1) {
          bVar3 = false;
        }
        if (param_1 * (float)puVar1[6] < fVar2) {
          bVar4 = false;
        }
      }
    }
    *(undefined4 *)(iVar5 + 0xc) = 0;
    if (bVar3) {
      *(undefined4 *)(iVar5 + 0xc) = 2;
      return;
    }
    if (!bVar4) {
      *(undefined4 *)(iVar5 + 0xc) = 4;
    }
  }
  return;
}


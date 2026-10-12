/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1d90; label: FUN_004f1d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1d90(void)

{
  int *piVar1;
  int in_EAX;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = -in_EAX;
  if (0 < *(int *)(in_EAX + 0x18)) {
    iVar3 = 0;
    do {
      psVar2 = (short *)(*(int *)(in_EAX + 0x14) + iVar3);
      if (0 < *psVar2) {
        piVar1 = (int *)(psVar2 + 2);
        *piVar1 = *piVar1 + iVar5;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar4 < *(int *)(in_EAX + 0x18));
  }
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + iVar5;
  *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + iVar5;
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1dd0; label: FUN_004f1dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f1dd0(void)

{
  int *piVar1;
  int in_EAX;
  short *psVar2;
  int iVar3;
  int iVar4;
  
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + in_EAX;
  *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + in_EAX;
  iVar4 = 0;
  if (0 < *(int *)(in_EAX + 0x18)) {
    iVar3 = 0;
    do {
      psVar2 = (short *)(*(int *)(in_EAX + 0x14) + iVar3);
      if (0 < *psVar2) {
        piVar1 = (int *)(psVar2 + 2);
        *piVar1 = *piVar1 + in_EAX;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0xc;
    } while (iVar4 < *(int *)(in_EAX + 0x18));
  }
  return;
}


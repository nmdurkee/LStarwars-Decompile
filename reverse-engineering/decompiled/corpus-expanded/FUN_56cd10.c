/* Ghidra pseudocode, not original source.
 * ev_6cd7b427fefd6a18a341146345d1c01d98fc33d6c80c45f814d5cdd3902e445d
 * Entry: 0x56cd10; label: FUN_0056cd10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056cd10(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    iVar2 = 0;
    if ((short)param_1[1] != 0) {
      do {
        if (*(int *)(iVar1 + 0x14) == param_2) {
          if ((*(uint *)(iVar1 + 0x1c) & 2) != 0) {
            return 0;
          }
          if ((*(uint *)(iVar1 + 0x1c) & 1) != 0) {
            return iVar1;
          }
          FUN_0056cab0(iVar1);
          if ((*(uint *)(iVar1 + 0x1c) & 1) != 0) {
            return iVar1;
          }
          *(uint *)(iVar1 + 0x1c) = *(uint *)(iVar1 + 0x1c) | 2;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x20;
      } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 1));
    }
  }
  return 0;
}


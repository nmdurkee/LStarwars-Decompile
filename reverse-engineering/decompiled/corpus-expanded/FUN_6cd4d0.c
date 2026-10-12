/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6cd4d0; label: FUN_006cd4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cd4d0(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_204;
  int local_200 [64];
  int local_100 [64];
  
  _memset(local_200,0,0x100);
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x24)) {
    iVar5 = 0;
    do {
      iVar3 = *(int *)(in_ECX + 8) + iVar5;
      if ((*(uint *)(param_1 + 0x1c) & 0x400000) == 0) {
        uVar2 = *(uint *)(iVar3 + 4) & 0x10000000;
      }
      else {
        uVar2 = *(uint *)(iVar3 + 4) & 0x400000;
      }
      if (uVar2 == 0) {
        local_204 = 0;
        FUN_006c6870(param_1,local_100,&local_204,0x40);
        iVar3 = 0;
        if (0 < local_204) {
          do {
            piVar1 = local_100 + iVar3;
            iVar3 = iVar3 + 1;
            local_200[*piVar1] = 1;
          } while (iVar3 < local_204);
        }
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x18;
    } while (iVar4 < *(int *)(in_ECX + 0x24));
  }
  iVar4 = 0;
  *param_3 = 0;
  if (0 < *(int *)(in_ECX + 0x24)) {
    iVar5 = (int)local_200 - (int)param_2;
    do {
      if (*(int *)(iVar5 + (int)param_2) == 0) {
        *param_2 = -1;
      }
      else {
        *param_2 = *param_3;
        *param_3 = *param_3 + 1;
      }
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x24));
  }
  return;
}


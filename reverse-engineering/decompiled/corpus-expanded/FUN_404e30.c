/* Ghidra pseudocode, not original source.
 * ev_e8754f098cec4467dd9989e7d0bc7b4ce6834c9196706effdc433d5dfb6256ff
 * Entry: 0x404e30; label: FUN_00404e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00404e30(int param_1)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int local_4;
  
  pbVar2 = &DAT_00854914;
  local_4 = 8;
  do {
    if (*(int *)(pbVar2 + 8) == param_1) {
      pbVar2[1] = 0;
      *pbVar2 = 0;
      pbVar2[8] = 0;
      pbVar2[9] = 0;
      pbVar2[10] = 0;
      pbVar2[0xb] = 0;
      pbVar2[0x30] = 0x32;
      pbVar2[0x31] = 0;
    }
    else if ((*pbVar2 != 0) && (iVar4 = 0, *pbVar2 != 0)) {
      pbVar5 = pbVar2 + -0x7c;
      do {
        if (*(int *)pbVar5 == param_1) {
          if (param_1 == *(int *)(pbVar2 + 8)) {
            pbVar2[1] = 0;
            *pbVar2 = 0;
            pbVar2[8] = 0;
            pbVar2[9] = 0;
            pbVar2[10] = 0;
            pbVar2[0xb] = 0;
            pbVar2[0x30] = 0x32;
            pbVar2[0x31] = 0;
          }
          else if (pbVar2[1] == 0) {
            pbVar1 = pbVar5;
            iVar3 = iVar4;
            if (iVar4 < (int)(*pbVar2 - 1)) {
              do {
                *(undefined4 *)pbVar1 = *(undefined4 *)(pbVar1 + 0x14);
                *(undefined4 *)(pbVar1 + 4) = *(undefined4 *)(pbVar1 + 0x18);
                *(undefined4 *)(pbVar1 + 8) = *(undefined4 *)(pbVar1 + 0x1c);
                *(undefined4 *)(pbVar1 + 0xc) = *(undefined4 *)(pbVar1 + 0x20);
                *(undefined4 *)(pbVar1 + 0x10) = *(undefined4 *)(pbVar1 + 0x24);
                iVar3 = iVar3 + 1;
                pbVar1 = pbVar1 + 0x14;
              } while (iVar3 < (int)(*pbVar2 - 1));
            }
            *pbVar2 = *pbVar2 - 1;
          }
          else {
            pbVar5[5] = 1;
          }
        }
        iVar4 = iVar4 + 1;
        pbVar5 = pbVar5 + 0x14;
      } while (iVar4 < (int)(uint)*pbVar2);
    }
    pbVar2 = pbVar2 + 0xb4;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  return;
}


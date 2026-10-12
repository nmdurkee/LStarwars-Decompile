/* Ghidra pseudocode, not original source.
 * ev_4aacc4015277efc7c796a4684ec1a2293d4b851b48a9fd84999ecda53bd8e95c
 * Entry: 0x501640; label: FUN_00501640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00501640(int param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  short sVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  uint local_4;
  
  iVar2 = *(int *)(param_1 + 0x1c);
  iVar6 = 0;
  local_4 = 0;
  if (*(char *)(iVar2 + 9) != '\0') {
    do {
      bVar1 = *(byte *)(*(int *)(iVar2 + 4) + 4 + iVar6);
      puVar7 = (undefined4 *)(*(int *)(iVar2 + 4) + iVar6);
      if ((bVar1 & 1) == 0) {
        if ((bVar1 & 2) == 0) {
          if ((bVar1 & 0x10) == 0) {
            if (((bVar1 & 4) != 0) && (DAT_009213b4 != (code *)0x0)) {
              sVar4 = (*DAT_009213b4)(*puVar7);
              *(short *)((int)puVar7 + 6) = sVar4;
              if (sVar4 != -1) {
                *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 4;
              }
            }
          }
          else if (DAT_00921328 == (code *)0x0) {
            *(undefined2 *)((int)puVar7 + 6) = 0xffff;
          }
          else {
            puVar5 = (undefined1 *)FUN_004f1fc0(*puVar7,0x5f);
            if (((puVar5 != (undefined1 *)0x0) && ('/' < (char)puVar5[1])) &&
               ((char)puVar5[1] < ':')) {
              *puVar5 = 0;
            }
            uVar3 = (*DAT_00921328)(*puVar7);
            *(undefined2 *)((int)puVar7 + 6) = uVar3;
          }
        }
        else {
          uVar3 = FUN_00501240();
          *(undefined2 *)((int)puVar7 + 6) = uVar3;
        }
      }
      else if (DAT_0092134c == 0) {
        uVar3 = FUN_00658490(*puVar7,param_2);
        *(undefined2 *)((int)puVar7 + 6) = uVar3;
      }
      else {
        uVar3 = FUN_00658470(*puVar7,param_2);
        *(undefined2 *)((int)puVar7 + 6) = uVar3;
      }
      if (*(short *)((int)puVar7 + 6) == -1) {
        FUN_004fff10(*puVar7);
      }
      local_4 = local_4 + 1;
      iVar6 = iVar6 + 0xc;
    } while (local_4 < *(byte *)(iVar2 + 9));
  }
  return;
}


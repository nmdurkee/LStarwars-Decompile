/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548460; label: FUN_00548460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548460(int param_1)

{
  short sVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
  sVar1 = *(short *)(iVar3 + 0xdc);
  if (sVar1 == -1) {
    if ((*(uint *)(iVar3 + 0x90) & 0x800) == 0) {
      uVar2 = *(uint *)(*(int *)(param_1 + 0x54) + 4);
      if ((uVar2 & 0x2000) == 0) {
        if ((uVar2 & 0x4000000) == 0) {
          if ((uVar2 & 0x10) == 0) {
            if ((uVar2 & 0x40000000) != 0) goto LAB_00548520;
            if ((*(uint *)(param_1 + 0xef4) & 0x800) == 0) {
              iVar3 = (int)*(short *)(PTR_DAT_008020bc + 400);
            }
            else {
              iVar3 = (int)*(short *)(PTR_DAT_008020bc + 0x18e);
            }
          }
          else {
            iVar3 = (int)*(short *)(PTR_DAT_008020bc + 0x18c);
          }
        }
        else {
          iVar3 = (int)*(short *)(PTR_DAT_008020bc + 0x18a);
        }
      }
      else {
        iVar3 = (int)*(short *)(PTR_DAT_008020bc + 0x188);
      }
    }
    else {
      iVar3 = (int)*(short *)(PTR_DAT_008020bc + 0x188);
    }
  }
  else {
    iVar3 = (int)sVar1;
  }
  if (iVar3 != -1) {
    FUN_00681e90(iVar3,param_1 + 0x80);
  }
LAB_00548520:
  if (DAT_00924de4 != (code *)0x0) {
    (*DAT_00924de4)(param_1);
  }
  return;
}


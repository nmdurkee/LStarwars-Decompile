/* Ghidra pseudocode, not original source.
 * ev_f0f87d832dbe8e7fa4eaa2c5681d260c3f1d1a42269eaf7f506f4d6846a5d20b
 * Entry: 0x548160; label: FUN_00548160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548160(int param_1)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  if (((*(short *)(param_1 + 0x106c) == -1) && (*(short *)(param_1 + 0x27e) == -1)) &&
     ((*(char *)(param_1 + 0x285) == -1 ||
      (((&DAT_008034cc)[*(char *)(param_1 + 0x285) * 0xc] & 2) == 0)))) {
    uVar4 = 0;
  }
  else {
    uVar4 = 1;
  }
  sVar1 = *(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xe6);
  if (sVar1 == -1) {
    if (*(code **)PTR_DAT_008020bc == (code *)0x0) {
LAB_005481d3:
      if ((*(char *)(param_1 + 0x286) == '\0') && (*(char *)(param_1 + 0x287) == '\0')) {
        iVar2 = FUN_0055f450();
        uVar3 = *(uint *)(*(int *)(iVar2 + 0x128) + 100) & 0x1000;
        if ((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x10) == 0) {
          if (uVar3 == 0) {
            iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x176);
          }
          else {
            iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x178);
          }
        }
        else if (uVar3 == 0) {
          iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x17a);
        }
        else {
          iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x17c);
        }
      }
      else {
        iVar2 = (int)*(short *)(PTR_DAT_008020bc + 0x17e);
      }
      goto LAB_00548250;
    }
    iVar2 = (**(code **)PTR_DAT_008020bc)(param_1,uVar4);
    if (iVar2 == -1) goto LAB_005481d3;
  }
  else {
    iVar2 = (int)sVar1;
LAB_00548250:
    if (iVar2 == -1) goto LAB_00548296;
  }
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) && ((*(uint *)(param_1 + 0xeec) & 0x8000000) == 0))
  {
    FUN_00681eb0(iVar2,param_1 + 0x19c,0x3f000000);
  }
  else {
    FUN_00681e90(iVar2,param_1 + 0x19c);
  }
LAB_00548296:
  if ((*(char *)(param_1 + 0x39) == '\0') && (*(short *)(param_1 + 0x3e) != -1)) {
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 0x50) + 8) + *(short *)(param_1 + 0x3e) * 4);
    if (iVar2 != 0) {
      uVar3 = *(uint *)(iVar2 + 4);
      if ((uVar3 & 0x20000) != 0) {
        FUN_00549de0(PTR_DAT_008021b4,0xbe800000,0,param_1 + 0x80);
        FUN_0054a910(0x3f19999a,0,0,0);
        return;
      }
      if (((uVar3 & 0x40000) != 0) && (DAT_00951288 == 0)) {
        FUN_00549bb0(PTR_DAT_008021b4,0x3f000000,0x3f000000,0x3f800000);
        FUN_0054a910(0x3f000000,0,0,0);
      }
    }
  }
  return;
}


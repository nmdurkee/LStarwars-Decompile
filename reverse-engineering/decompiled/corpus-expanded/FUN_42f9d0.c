/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42f9d0; label: FUN_0042f9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0042f9d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 local_10;
  undefined1 local_c [12];
  
  FUN_00562010(param_1,local_c,0);
  uVar4 = 0x17;
  if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
    iVar2 = FUN_0056e160(0x16);
    if (iVar2 != 0) {
      uVar4 = 0x37;
      local_10 = 0x3f800000;
      uVar3 = 2;
      uVar1 = 0x3f000000;
      goto LAB_0042fa31;
    }
  }
  uVar3 = 1;
  local_10 = 0x3f19999a;
  uVar1 = 0x3e99999a;
LAB_0042fa31:
  iVar2 = FUN_0056e5f0(local_c,local_10,uVar1,param_1,(int)*(char *)(param_1 + 0xe40),uVar4);
  if (iVar2 != 0) {
    *(undefined1 *)(iVar2 + 0x32) = uVar3;
  }
  return;
}


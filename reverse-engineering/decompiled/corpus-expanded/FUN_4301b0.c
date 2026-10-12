/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x4301b0; label: FUN_004301b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004301b0(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0xd4);
  if (iVar1 != 0) {
    sVar2 = FUN_0062c3b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),"CRATE_POP");
    if (sVar2 != -1) {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)sVar2,param_1 + 0x30);
    }
    iVar3 = FUN_0064afd0("CRATE_PART");
    if (iVar3 != -1) {
      FUN_0064b370(iVar3,param_1 + 0x30,1);
    }
    *(uint *)(iVar1 + 0x1fc) = *(uint *)(iVar1 + 0x1fc) | 0x1000;
    *(undefined1 *)(iVar1 + 0x406) = 2;
    FUN_00681f40("Explode1",param_1 + 0x30);
    FUN_00549de0(PTR_DAT_008021b4,0x3dcccccd,0,0);
    FUN_0054a910(0,0,2,0);
  }
  return;
}


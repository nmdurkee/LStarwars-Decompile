/* Ghidra pseudocode, not original source.
 * ev_3150f882b42e5d0bb9c96a5fbbe185870406793ef78dd50970469a73867d11f4
 * Entry: 0x649230; label: FUN_00649230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00649230(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  DAT_029209f0 = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,&LAB_00649210,"Part Type");
  if ((DAT_029209f0 != 0) && (DAT_02920970 != 0)) {
    iVar2 = -1;
    if (DAT_00810190 == 3) {
      iVar2 = *(int *)(DAT_02920970 + 0x130);
    }
    uVar1 = FUN_00627b80(0xffffffff,&DAT_008109d8,iVar2 == -1,1,FUN_006491f0,&DAT_00763b90);
    FUN_00618e10(DAT_029209f0,uVar1);
    pcVar3 = &DAT_02913a58;
    iVar4 = 0;
    do {
      if ((*pcVar3 != '\0') && (pcVar3[0xb3] == DAT_02920990)) {
        if (iVar4 == *(int *)(DAT_0292096c + 0xc)) {
          uVar1 = FUN_00627b80(iVar4,&DAT_008109e8,0,0,0,pcVar3);
        }
        else {
          uVar1 = FUN_00627b80(iVar4,&DAT_008109d8,iVar2 == iVar4,1,FUN_006491f0,pcVar3);
        }
        FUN_00618e10(DAT_029209f0,uVar1);
        if (iVar2 == iVar4) {
          *(undefined4 *)(DAT_029209f0 + 8) = DAT_02900c84;
        }
      }
      pcVar3 = pcVar3 + 0x178;
      iVar4 = iVar4 + 1;
    } while ((int)pcVar3 < 0x291f658);
    FUN_006279b0(param_1,DAT_029209f0);
    *(int *)(DAT_029209f0 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209f0 + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


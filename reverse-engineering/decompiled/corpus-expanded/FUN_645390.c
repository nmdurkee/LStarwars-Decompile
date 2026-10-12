/* Ghidra pseudocode, not original source.
 * ev_e99a99ac40850efc4319cfa1070f50eca7ba45fd57a73000da90cd7b4a6a9b3b
 * Entry: 0x645390; label: FUN_00645390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00645390(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  
  DAT_029209ac = FUN_00619250(0x46,0x46,0xfa,0xfa,DAT_02912e80,FUN_00645370,"Emitter Type (General)"
                             );
  if (DAT_029209ac != 0) {
    if (DAT_02920a94 < 0x80) {
      uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00645260,"Add Type");
    }
    else {
      uVar1 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Add Type");
    }
    FUN_00618e10(DAT_029209ac,uVar1);
    iVar2 = 0;
    pcVar3 = &DAT_02913a58;
    do {
      if ((*pcVar3 != '\0') && (pcVar3[0xb3] == '\0')) {
        bVar4 = DAT_00810194 == iVar2;
        uVar1 = FUN_00627b80(iVar2,&DAT_008109d8,bVar4,1,FUN_00644ca0,pcVar3);
        FUN_00618e10(DAT_029209ac,uVar1);
        if (bVar4) {
          *(undefined4 *)(DAT_029209ac + 8) = DAT_02900c84;
        }
      }
      pcVar3 = pcVar3 + 0x178;
      iVar2 = iVar2 + 1;
    } while ((int)pcVar3 < 0x291f658);
    FUN_006279b0(param_1,DAT_029209ac);
    *(int *)(DAT_029209ac + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029209ac + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


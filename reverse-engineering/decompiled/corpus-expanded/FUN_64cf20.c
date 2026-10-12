/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64cf20; label: FUN_0064cf20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0064cf20(void)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  char *pcVar4;
  
  DAT_029209a4 = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,&LAB_0064a260,"PART Editor");
  if (DAT_029209a4 != 0) {
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00645730,"Emitter Type...");
    FUN_00618e10(DAT_029209a4,uVar2);
    if (DAT_02920888 == -1) {
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Instance Select...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Instance Settings...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Emitter Settings...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Debris Settings...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Attached Sounds...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Switch Menu...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109e8,0,0,0,"Scale Type...");
    }
    else {
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_006462e0,"Instance Select...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649450,"Instance Settings...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0064a010,"Emitter Settings...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00649e20,"Debris Settings...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00646b50,"Attached Sounds...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00644f50,"Switch Menu...");
      FUN_00618e10(DAT_029209a4,uVar2);
      uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00645170,"Scale Type...");
    }
    FUN_00618e10(DAT_029209a4,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0064ccb0,"Data Menu...");
    FUN_00618e10(DAT_029209a4,uVar2);
    uVar2 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_00647640,"Super Scale...");
    FUN_00618e10(DAT_029209a4,uVar2);
    uVar2 = FUN_00627bc0(1,&DAT_008109d8,DAT_02920994,1,FUN_0064a220,"Instance Filter");
    FUN_00618e10(DAT_029209a4,uVar2);
    uVar2 = FUN_00627c00(0,&DAT_008109d8,FUN_0064a240,"Filter String: ");
    FUN_00618e10(DAT_029209a4,uVar2);
    pcVar3 = &DAT_008101a8;
    pcVar4 = (char *)(DAT_02900c84 + 0x4c);
    do {
      cVar1 = *pcVar3;
      *pcVar4 = cVar1;
      pcVar3 = pcVar3 + 1;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    *(undefined2 *)(DAT_02900c84 + 0x15a) = 0xf;
  }
  return;
}


/* Ghidra pseudocode, not original source.
 * ev_119981038e8c19adfdb272c0e357e55b3a12ebc602b993d3e023990f2be0b94d
 * Entry: 0x68ba50; label: FUN_0068ba50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0068ba50(int param_1)

{
  undefined4 uVar1;
  
  DAT_029629bc = FUN_00619250(0x46,0x46,0xdc,300,DAT_02912e80,FUN_0065f860,
                              "Global Options (Take Care!)");
  if (DAT_029629bc != 0) {
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0065f7c0,0,(float)DAT_00810a94 * 100.0,_DAT_00810a98,
                         "Global Start of Fade");
    FUN_00618e10(DAT_029629bc,uVar1);
    DAT_029629c8 = DAT_02900c84;
    FUN_0061d880(DAT_02900c84,"(%1.01f)");
    FUN_0061d900(DAT_02900c84,0x3dcccccd);
    uVar1 = FUN_00625150(0,&DAT_008109d8,0,FUN_0065f810,0,(float)DAT_00810a94 * 100.0,_DAT_00810a9c,
                         "Global End of Fade");
    FUN_00618e10(DAT_029629bc,uVar1);
    DAT_029629cc = DAT_02900c84;
    FUN_0061d880(DAT_02900c84,"(%1.01f)");
    FUN_0061d900(DAT_02900c84,0x3dcccccd);
    uVar1 = FUN_00627a80(1,&DAT_008109d8,0,0,FUN_0068b9d0,"Apply Globally (Careful!)");
    FUN_00618e10(DAT_029629bc,uVar1);
    FUN_006279b0(param_1,DAT_029629bc);
    *(int *)(DAT_029629bc + 0x14) = *(int *)(param_1 + 0x14) + 10;
    *(int *)(DAT_029629bc + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  }
  return;
}


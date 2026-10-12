/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x534bc0; label: FUN_00534bc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00534bc0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Group Values"), iVar1 != 0
     )) {
    uVar2 = FUN_00625240(1,&DAT_00801cb4,0,&LAB_00534a80,1,0x1f,
                         *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5b),"Group Size");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_005291d0,0,0x42700000,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x98),"Stagger Time");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625240(1,&DAT_00801cb4,0,FUN_00534ae0,1,0x1f,
                         *(undefined1 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5c),"Formation Width")
    ;
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_00534b40,0x3e4ccccd,0x4099999a,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x60),
                         "Formation X Spacing");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_00534b80,0x3e4ccccd,0x4099999a,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 100),
                         "Formation Z Spacing");
    FUN_00618e10(iVar1,uVar2);
    FUN_006279b0(param_1,iVar1);
  }
  return;
}


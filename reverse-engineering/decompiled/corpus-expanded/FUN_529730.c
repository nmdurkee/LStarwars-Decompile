/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529730; label: FUN_00529730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529730(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*(int *)(DAT_009238e4 + 0x371b0) != 0) &&
     (iVar1 = FUN_00619250(0xdc,0x46,0xf0,0xfa,DAT_02912e80,FUN_00528d00,"Vision"), iVar1 != 0)) {
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_005295d0,0x3f000000,0x42460000,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x9c),"View Distance");
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_00529650,0x3f000000,0x42460000,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa0),"Hearing Distance"
                        );
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_005296d0,0x3dcccccd,0x42c7cccd,
                         *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa4),"Max View Height")
    ;
    FUN_00618e10(iVar1,uVar2);
    uVar2 = FUN_00625150(1,&DAT_00801cb4,0,FUN_00529700,0x3dcccccd,0x42c7cccd,
                         -*(float *)(*(int *)(DAT_009238e4 + 0x371b0) + 0xa8),"Min View Height -");
    FUN_00618e10(iVar1,uVar2);
    FUN_006279b0(param_1,iVar1);
  }
  return;
}


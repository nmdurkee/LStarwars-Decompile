/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56d340; label: FUN_0056d340
 */

undefined4 FUN_0056d340(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  if (*(int *)(param_1 + 0x4694) == 0) {
    iVar2 = FUN_006217e0();
    iVar3 = FUN_006217e0();
    iVar4 = *(int *)(param_1 + 0x4690);
    iVar5 = 0;
    *(int *)(param_1 + 0x4694) = iVar3;
    if (0 < iVar3) {
      do {
        FUN_006216f0(iVar4,0x10);
        FUN_00621900(iVar4 + 0x10);
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar4 + 0x1c) = (float)fVar6;
        fVar6 = (float10)FUN_006217a0();
        *(float *)(iVar4 + 0x20) = (float)fVar6;
        if (iVar2 < 2) {
          *(byte *)(iVar4 + 0x34) = *(byte *)(iVar4 + 0x34) & 0xfb;
        }
        else {
          cVar1 = FUN_006218c0();
          *(byte *)(iVar4 + 0x34) =
               *(byte *)(iVar4 + 0x34) ^ ((cVar1 != '\0') * '\x04' ^ *(byte *)(iVar4 + 0x34)) & 4;
        }
        iVar5 = iVar5 + 1;
        *(undefined4 *)(iVar4 + 0x24) = 0x3fa00000;
        iVar4 = iVar4 + 0x40;
      } while (iVar5 < *(int *)(param_1 + 0x4694));
    }
    return 1;
  }
  return 0;
}


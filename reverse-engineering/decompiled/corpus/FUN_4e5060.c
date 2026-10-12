/* Ghidra analysis pseudocode, not original source.
 * ev_1b769233bdb8589f5b6c19d1b053d2efd2e6005a2a8cafb96b11ff416f994ddb
 * Entry: 0x4e5060; label: FUN_004e5060
 */

void FUN_004e5060(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  float10 fVar6;
  
  iVar4 = 0;
  puVar5 = &DAT_0087aad8;
  do {
    if ((&DAT_0087aa20)[iVar4] == '\0') {
      uVar2 = FUN_005cf9e0(puVar5);
      iVar3 = FUN_005d0420(puVar5);
      if (iVar3 != 0) {
        fVar1 = *(float *)(iVar3 + 0x4c);
        fVar6 = (float10)FUN_005ca4b0(*(undefined4 *)
                                       (*(int *)(*(int *)(param_1 + 0x13c) + 0x54) +
                                       (uint)*(ushort *)(iVar3 + 0x5c) * 4));
        FUN_00681eb0(DAT_0087aa7c,uVar2,0x3e800000);
        if (fVar6 < (float10)fVar1 != (fVar6 == (float10)fVar1)) {
          FUN_00681eb0(DAT_0087aa80,0,0x3ecccccd);
          (&DAT_0087aa20)[iVar4] = 1;
        }
      }
    }
    puVar5 = puVar5 + 3;
    iVar4 = iVar4 + 1;
  } while ((int)puVar5 < 0x87ab20);
  return;
}


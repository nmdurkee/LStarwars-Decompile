/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4db130; label: FUN_004db130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_004db130(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  if ((param_6 != 0) && (*(float *)(DAT_00882a6c + 0xb00c) == 0.0)) {
    iVar4 = 0;
    iVar1 = DAT_00882a6c;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"maxlaptime=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"laptime=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"nattempts_per_increment=");
            if (iVar1 == 0) {
              iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"increment=");
              iVar1 = DAT_00882a6c;
              if (iVar3 != 0) {
                fVar5 = (float10)FUN_005147c0(param_3,iVar3 + 10);
                iVar1 = DAT_00882a6c;
                *(float *)(DAT_00882a6c + 0xb014) = (float)fVar5;
              }
            }
            else {
              FUN_005147c0(param_3,iVar1 + 0x18);
              uVar2 = FUN_006e6b90();
              iVar1 = DAT_00882a6c;
              *(undefined4 *)(DAT_00882a6c + 0xb018) = uVar2;
            }
          }
          else {
            fVar5 = (float10)FUN_005147c0(param_3,iVar1 + 8);
            iVar1 = DAT_00882a6c;
            *(float *)(DAT_00882a6c + 0xb00c) = (float)fVar5;
          }
        }
        else {
          fVar5 = (float10)FUN_005147c0(param_3,iVar1 + 0xb);
          iVar1 = DAT_00882a6c;
          *(float *)(DAT_00882a6c + 0xb010) = (float)fVar5;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (*(float *)(iVar1 + 0xb010) == 0.0) {
      *(undefined4 *)(iVar1 + 0xb010) = *(undefined4 *)(iVar1 + 0xb00c);
      return 1;
    }
  }
  return 1;
}


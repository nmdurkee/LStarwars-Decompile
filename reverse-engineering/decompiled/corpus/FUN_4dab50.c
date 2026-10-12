/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4dab50; label: FUN_004dab50
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_004dab50(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if ((param_6 != 0) && (DAT_00882a78 == 0)) {
    iVar2 = 0;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"trigger_crash=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"trigger_collapse=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"max_time_available=");
            if (iVar1 == 0) {
              iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"time_available=");
              if (iVar1 == 0) {
                iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),"time_increment=");
                if (iVar1 == 0) {
                  iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar2 * 4),
                                       "nattempts_per_increment=");
                  if (iVar1 != 0) {
                    FUN_005147c0(param_3,iVar1 + 0x18);
                    DAT_00882904 = FUN_006e6b90();
                  }
                }
                else {
                  fVar3 = (float10)FUN_005147c0(param_3,iVar1 + 0xf);
                  _DAT_007ffd40 = (float)fVar3;
                }
              }
              else {
                fVar3 = (float10)FUN_005147c0(param_3,iVar1 + 0xf);
                _DAT_007ffd34 = (float)fVar3;
              }
            }
            else {
              fVar3 = (float10)FUN_005147c0(param_3,iVar1 + 0x13);
              _DAT_007ffd38 = (float)fVar3;
            }
          }
          else {
            fVar3 = (float10)FUN_005147c0(param_3,iVar1 + 0x11);
            _DAT_007ffd30 = (float)fVar3;
          }
        }
        else {
          fVar3 = (float10)FUN_005147c0(param_3,iVar1 + 0xe);
          _DAT_007ffd2c = (float)fVar3;
        }
        if (_DAT_007ffd38 < _DAT_007ffd34) {
          _DAT_007ffd38 = _DAT_007ffd34;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_5);
    }
    DAT_00882a78 = 1;
    return 1;
  }
  return 1;
}


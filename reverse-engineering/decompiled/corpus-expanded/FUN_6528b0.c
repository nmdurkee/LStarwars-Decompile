/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x6528b0; label: FUN_006528b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006528b0(int param_1,float param_2)

{
  undefined4 uVar1;
  short sVar2;
  
  if (param_2 < 0.0) {
    param_2 = _DAT_008104a4;
  }
  if (-1 < param_1) {
    if (param_1 <= DAT_0296202c + -1) {
      sVar2 = (short)param_1;
      if (((DAT_00810490 == 0xb) || (DAT_00810490 == 0xc)) || (DAT_00810490 == 0xd)) {
        if ((DAT_00810496 != param_1) || (DAT_008104a0 != '\0')) {
          DAT_00810492 = 0xffff;
          DAT_00810490 = 0xb;
          DAT_00810496 = sVar2;
          DAT_0081049a = sVar2;
          (&DAT_008104a2)[DAT_00810494] = 0;
          if (0x3f < DAT_00810498) {
            DAT_008104a0 = 0;
            uVar1 = FUN_006e6b90(param_2);
            FUN_006524a0(param_1,uVar1);
            _DAT_008104a4 = 0.0;
            DAT_00810498 = 0;
            return;
          }
          DAT_008104a0 = '\x01';
        }
      }
      else if (param_1 <= DAT_0296202c + -1) {
        DAT_00810490 = 4;
        DAT_008104a0 = 0;
        DAT_00810498 = 0;
        DAT_00810492 = sVar2;
        DAT_00810496 = sVar2;
        DAT_0081049a = sVar2;
        (&DAT_008104a2)[DAT_00810494] = 0;
        uVar1 = FUN_006e6b90(param_2);
        FUN_006524a0(param_1,uVar1);
        return;
      }
    }
    return;
  }
  return;
}


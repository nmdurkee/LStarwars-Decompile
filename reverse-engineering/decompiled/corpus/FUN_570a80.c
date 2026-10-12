/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x570a80; label: FUN_00570a80
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00570a80(uint *param_1,int param_2,byte param_3)

{
  uint uVar1;
  float fVar2;
  uint uVar3;
  float10 fVar4;
  uint local_8;
  
  if (param_1 != (uint *)0x0) {
    if (param_2 == 0) {
      *(undefined1 *)((int)param_1 + 10) = 1;
      param_1[1] = 0x3f800000;
      param_1[3] = 0;
      if (DAT_00951154 != 0) {
        uVar1 = *param_1;
        if (9 < uVar1) {
          local_8 = (uint)(longlong)ROUND(_DAT_00925018 * 20000.0);
          uVar3 = (local_8 / 10) * 10;
          if (uVar3 < 10) {
            uVar3 = 10;
          }
          if (uVar3 <= uVar1) {
            *param_1 = uVar1 - uVar3;
            return;
          }
        }
        *param_1 = 0;
        return;
      }
    }
    else {
      fVar4 = (float10)FUN_0054fad0(param_1[1],0x3f800000,_DAT_00925018 * 3.0);
      param_1[1] = (uint)(float)fVar4;
      if ((DAT_0087b924 & 1 << (param_3 & 0x1f)) == 0) {
        param_1[3] = 0;
        *(undefined1 *)((int)param_1 + 10) = 1;
        return;
      }
      if (0.0 < (float)param_1[3]) {
        fVar2 = (float)param_1[3] - _DAT_00925018;
        param_1[3] = (uint)fVar2;
        if (fVar2 < 0.0 != (fVar2 == 0.0)) {
          *(undefined1 *)((int)param_1 + 10) = 1;
          return;
        }
      }
    }
  }
  return;
}


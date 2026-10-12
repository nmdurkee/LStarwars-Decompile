/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x608460; label: FUN_00608460
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00608460(float param_1,float param_2,uint param_3,int param_4,int param_5)

{
  float fVar1;
  
  _DAT_02854d5c = param_1;
  _DAT_02854d68 = param_4 << 0x18;
  _DAT_02854d60 = param_2;
  _DAT_02854d8c = param_5 >> 0x18 & 0xff;
  DAT_02854d64 = (param_3 >> 0x10 & 0xff) + (param_3 & 0xff) * 0x10000 + (param_3 & 0xff000000) +
                 (param_3 & 0xff00);
  if ((param_2 != param_1) && (0x2000000 < (param_3 & 0xff000000))) {
    _DAT_02854c8c = 1;
    FUN_006e5340(0x1c,1);
    FUN_006e5340(0x23,1);
    _DAT_0280d818 = DAT_02854d64 & 0xffffff;
    FUN_006e5340(0x22,DAT_02854d64);
    fVar1 = _DAT_02854d60;
    _DAT_02854c90 = 0;
    FUN_006e5340(0x24,_DAT_02854d5c);
    FUN_006e5340(0x25,fVar1);
    FUN_006e5340(0x26,_DAT_0080e6a8);
    return;
  }
  _DAT_02854c8c = 0;
  FUN_006e5340(0x1c,0);
  FUN_006e5340(0x23,0);
  return;
}


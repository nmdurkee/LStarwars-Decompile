/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fd4d0; label: FUN_005fd4d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fd4d0(size_t param_1,int *param_2)

{
  void *_Dst;
  
  if (param_2 == (int *)0x0) {
    DAT_00992290 = (void *)FUN_004eef40(param_1,
                                        "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nustream.c"
                                        ,0x7e);
    _Dst = (void *)FUN_004eef40(param_1,
                                "d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\pc\\nustream.c",0x7f);
  }
  else {
    DAT_00992290 = (void *)(*param_2 + 0x1fU & 0xffffffe0);
    _Dst = (void *)((int)DAT_00992290 + param_1 + 0x1f & 0xffffffe0);
    *param_2 = (int)_Dst + param_1;
  }
  DAT_02854c34 = param_1;
  DAT_02854c38 = 0;
  DAT_028490ec = _Dst;
  _memset(DAT_00992290,0,param_1);
  _memset(_Dst,0,param_1);
  FUN_005fd3f0();
  return;
}


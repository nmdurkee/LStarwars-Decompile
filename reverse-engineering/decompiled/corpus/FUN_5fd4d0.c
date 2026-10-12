/* Ghidra analysis pseudocode, not original source.
 * ev_6b9b03a08e90b2df5bf3c313ce6606e542f48a6b83443b8cc9ea7bf85be4ed2c
 * Entry: 0x5fd4d0; label: FUN_005fd4d0
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
  if (DAT_02854c38 == 0) {
    DAT_02854b88 = DAT_02854c34 + (int)DAT_00992290;
    DAT_0097c1ac = DAT_00992290;
  }
  else if (DAT_02854c38 == 1) {
    DAT_02854b88 = (int)DAT_028490ec + DAT_02854c34;
    DAT_0097c1ac = DAT_028490ec;
  }
  if (((uint)DAT_0097c1ac & 0xf) != 0) {
    DAT_0097c1ac = (void *)((int)DAT_0097c1ac + 0xfU & 0xfffffff0);
  }
  return;
}


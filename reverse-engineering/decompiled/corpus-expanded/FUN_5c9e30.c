/* Ghidra pseudocode, not original source.
 * ev_506f2ef4e11b68e7edff25e0427d0f13a0f8158f7d3b962ea2de52b74731d8d7
 * Entry: 0x5c9e30; label: FUN_005c9e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_005c9e30(int param_1)

{
  size_t _Size;
  void *_Dst;
  
  _Size = param_1 * 4 + 0x10;
  _Dst = (void *)FUN_004eef40(_Size,"d:\\projects\\legosagapc\\nu2api.saga\\nu3d\\nuanim.c",0x4bb);
  _memset(_Dst,0,_Size);
  *(int *)((int)_Dst + 0xc) = (int)_Dst + 0x10;
  *(int *)((int)_Dst + 8) = param_1;
  return _Dst;
}


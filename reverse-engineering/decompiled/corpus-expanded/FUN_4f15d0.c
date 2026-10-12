/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f15d0; label: FUN_004f15d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_004f15d0(undefined4 *param_1)

{
  undefined4 *_Dst;
  undefined4 uVar1;
  
  _Dst = (undefined4 *)*param_1;
  if (_Dst != (undefined4 *)0x0) {
    uVar1 = *_Dst;
    *(short *)((int)param_1 + 0xe) = *(short *)((int)param_1 + 0xe) + -1;
    *param_1 = uVar1;
    _memset(_Dst,-1,param_1[1]);
  }
  return _Dst;
}


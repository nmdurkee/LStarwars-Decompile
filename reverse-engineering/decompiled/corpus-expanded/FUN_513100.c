/* Ghidra pseudocode, not original source.
 * ev_689adb3d6d828c171b0bfd6ed2f80b610faff66ca987df996964ae40ef93a262
 * Entry: 0x513100; label: FUN_00513100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_00513100(int param_1,uint *param_2)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  int *unaff_EDI;
  
  _Dst = (void *)0x0;
  if (param_1 != 0) {
    iVar1 = FUN_004f1ff0(param_1);
    if (iVar1 != 0) {
      _Size = iVar1 + 1;
      if (((unaff_EDI != (int *)0x0) && (param_2 != (uint *)0x0)) && (*unaff_EDI + _Size < *param_2)
         ) {
        uVar2 = *unaff_EDI + 0xf;
        _Dst = (void *)(uVar2 & 0xfffffff0);
        *unaff_EDI = (uVar2 & 0xfffffff0) + _Size;
        _memset(_Dst,0,_Size);
      }
      FUN_004f1f10(_Dst,param_1);
    }
  }
  return _Dst;
}


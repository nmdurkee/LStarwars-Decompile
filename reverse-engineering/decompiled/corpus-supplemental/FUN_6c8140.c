/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x6c8140; label: FUN_006c8140
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

void FUN_006c8140(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 *unaff_EBX;
  void *_Dst;
  uint unaff_ESI;
  undefined1 local_4 [4];
  
  (**(code **)(*in_ECX + 8))(local_4,4,1);
  puVar1 = (undefined4 *)in_ECX[5];
  puVar2 = (uint *)*puVar1;
  _Dst = (void *)0x0;
  if (unaff_ESI < *(int *)puVar1[1] - *puVar2) {
    *puVar2 = *puVar2 + 0xf & 0xfffffff0;
    piVar3 = (int *)*puVar1;
    _Dst = (void *)*piVar3;
    *piVar3 = *piVar3 + unaff_ESI;
    _memset(_Dst,0,unaff_ESI);
    puVar1[2] = puVar1[2] + unaff_ESI;
    puVar1[3] = puVar1[3] - unaff_ESI;
  }
  *unaff_EBX = _Dst;
  (**(code **)(*in_ECX + 8))(_Dst,1,unaff_ESI);
  return;
}


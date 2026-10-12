/* Ghidra pseudocode, not original source.
 * ev_a9f7d46c3c3ea24b7c836492e4a4f03af3d55017d7b1673032296e60a08e4c88
 * Entry: 0x4f1780; label: FUN_004f1780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f1780(void *param_1)

{
  void *_Dst;
  int iVar1;
  int in_EAX;
  void *pvVar2;
  undefined1 *puVar3;
  int unaff_ESI;
  short *psVar4;
  
  iVar1 = in_EAX * 0xc;
  _Dst = *(void **)(iVar1 + 4 + *(int *)(unaff_ESI + 0x14));
  if (_Dst == (void *)0x0) {
    if (*(int *)(unaff_ESI + 0x28) - *(int *)(unaff_ESI + 0x24) <= *(int *)(unaff_ESI + 0x2c)) {
      *(int *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x14)) =
           *(int *)(unaff_ESI + 0x20) + *(int *)(unaff_ESI + 0x24);
      _memcpy((void *)0x0,param_1,*(size_t *)(unaff_ESI + 0x2c));
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + *(int *)(unaff_ESI + 0x2c);
      psVar4 = (short *)(iVar1 + *(int *)(unaff_ESI + 0x14));
      *psVar4 = *psVar4 + 1;
      return 1;
    }
  }
  else {
    pvVar2 = (void *)(*(int *)(unaff_ESI + 0x24) + *(int *)(unaff_ESI + 0x20));
    puVar3 = (undefined1 *)(*(int *)(unaff_ESI + 0x2c) + (int)pvVar2);
    if (puVar3 <= (undefined1 *)(*(int *)(unaff_ESI + 0x28) + *(int *)(unaff_ESI + 0x20))) {
      for (; pvVar2 != _Dst; pvVar2 = (void *)((int)pvVar2 + -1)) {
        puVar3 = puVar3 + -1;
        *puVar3 = *(undefined1 *)((int)pvVar2 + -1);
      }
      _memcpy(_Dst,param_1,*(size_t *)(unaff_ESI + 0x2c));
      *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + *(int *)(unaff_ESI + 0x2c);
      psVar4 = (short *)(*(int *)(unaff_ESI + 0x14) + iVar1);
      *psVar4 = *psVar4 + 1;
      return 1;
    }
  }
  return 0;
}


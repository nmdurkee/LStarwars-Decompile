/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab2d0; label: FUN_005ab2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ab2d0(void)

{
  undefined4 uVar1;
  void *unaff_ESI;
  
  if (unaff_ESI != (void *)0x0) {
    uVar1 = *(undefined4 *)((int)unaff_ESI + 0x18);
    _memset(unaff_ESI,0,0x13c);
    *(uint *)((int)unaff_ESI + 0x108) = *(uint *)((int)unaff_ESI + 0x108) | 0x802;
    *(undefined4 *)((int)unaff_ESI + 0xfc) = 0x3f800000;
    *(ushort *)((int)unaff_ESI + 0x13a) = *(ushort *)((int)unaff_ESI + 0x13a) & 0xf7fe;
    *(undefined4 *)((int)unaff_ESI + 0x100) = 0x41000000;
    *(undefined4 *)((int)unaff_ESI + 0x104) = 0x41000000;
    *(undefined4 *)((int)unaff_ESI + 0x18) = uVar1;
    *(undefined1 *)((int)unaff_ESI + 0x12f) = 1;
    *(undefined1 *)((int)unaff_ESI + 0x131) = 1;
    *(undefined2 *)((int)unaff_ESI + 0x12a) = 0xffff;
    *(undefined2 *)((int)unaff_ESI + 0x126) = 0xffff;
    *(undefined2 *)((int)unaff_ESI + 0x138) = 0xffff;
    *(undefined1 *)((int)unaff_ESI + 0x130) = 1;
    *(undefined2 *)((int)unaff_ESI + 0x124) = 0xffff;
    *(undefined1 *)((int)unaff_ESI + 0x12d) = 0xff;
    if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
       ((*(byte *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 1) != 0)) {
      *(undefined4 *)((int)unaff_ESI + 0x120) = 0x41400000;
      return;
    }
    *(undefined4 *)((int)unaff_ESI + 0x120) = 0x3fe00000;
  }
  return;
}


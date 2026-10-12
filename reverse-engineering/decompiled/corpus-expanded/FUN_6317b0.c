/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x6317b0; label: FUN_006317b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006317b0(int *param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 auStack_8 [2];
  
  _BinkDoFrame_4(*param_1);
  iVar1 = FUN_00633290(param_1,auStack_8,&uStack_c,&iStack_10,&uStack_14,&uStack_18,&uStack_1c,
                       &stack0xffffffe0,1);
  while (iVar1 != 0) {
    _BinkCopyToBufferRect_44
              (*param_1,auStack_8[0],uStack_c,*(undefined4 *)(*param_1 + 4),0,0,uStack_14,uStack_18,
               uStack_1c,unaff_ESI,
               -(uint)(DAT_0080fc60 != 0) & 0x80000000 | *(uint *)(&DAT_029131d4 + iStack_10 * 4));
    FUN_006332c0(param_1);
    iVar1 = FUN_00633290(param_1,auStack_8,&uStack_c,&iStack_10,&uStack_14,&uStack_18,&uStack_1c,
                         &stack0xffffffe0,1);
  }
  return 0;
}


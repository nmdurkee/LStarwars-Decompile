/* Ghidra pseudocode, not original source.
 * ev_c80330773f662e8a33570a4ca58388b0b4349f11aa110fb6d722955620f1df5d
 * Entry: 0x632020; label: FUN_00632020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 * FUN_00632020(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *_Memory;
  undefined4 uVar3;
  int *piStack_1a4;
  undefined4 uStack_1a0;
  int *piStack_19c;
  undefined1 *puStack_198;
  undefined1 auStack_174 [12];
  undefined4 local_168;
  undefined1 local_164 [8];
  undefined4 uStack_15c;
  int *piStack_158;
  undefined4 uStack_154;
  uint uStack_124;
  int *piStack_8;
  
  local_168 = 0;
  _memset(local_164,0,0x34);
  piVar1 = (int *)Direct3DCreate9();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x20))();
    if (-1 < iVar2) {
      puStack_198 = (undefined1 *)0x63207a;
      _Memory = _malloc(0x28);
      if (_Memory != (undefined4 *)0x0) {
        uStack_1a0 = 0x63208f;
        piStack_19c = piVar1;
        iVar2 = FUN_00631e90();
        if (iVar2 != 0) {
          puStack_198 = &stack0xfffffe78;
          piStack_19c = (int *)auStack_174;
          uStack_1a0 = 0x40;
          piStack_1a4 = piStack_8;
          piStack_158 = piStack_8;
          uStack_154 = 1;
          uStack_15c = 1;
          uVar3 = 0;
          iVar2 = (**(code **)(*piVar1 + 0x40))(piVar1,0,1);
          if (iVar2 < 0) {
            iVar2 = (**(code **)(*piVar1 + 0x40))
                              (piVar1,0,1,piStack_8,0x20,&stack0xfffffe70,&piStack_1a4);
            if (iVar2 < 0) {
              _free(_Memory);
              (**(code **)(*piVar1 + 8))(piVar1);
              return (undefined4 *)0x0;
            }
          }
          (**(code **)(*piStack_1a4 + 0x1c))(piStack_1a4,&piStack_158);
          *_Memory = piVar1;
          _Memory[9] = uStack_124 >> 8 & 1;
          _Memory[2] = piStack_8;
          _Memory[1] = uVar3;
          return _Memory;
        }
      }
      puStack_198 = (undefined1 *)0x63209e;
      (**(code **)(*piVar1 + 8))();
      return (undefined4 *)0x0;
    }
    (**(code **)(*piVar1 + 8))();
  }
  return (undefined4 *)0x0;
}


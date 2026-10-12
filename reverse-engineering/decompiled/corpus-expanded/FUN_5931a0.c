/* Ghidra pseudocode, not original source.
 * ev_b142addbfc413d4476e6a560937bb6deb0d869285f4b587c6bb2379626f1bfc8
 * Entry: 0x5931a0; label: FUN_005931a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005931a0(int *param_1,int param_2)

{
  uint *puVar1;
  void *_Dst;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  int local_1a0;
  int local_19c;
  int *local_198;
  int *local_194;
  undefined4 local_190;
  int local_18c;
  size_t local_188;
  undefined1 local_184 [128];
  undefined1 local_104 [128];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_1a0;
  local_194 = param_1;
  local_1a0 = param_2;
  if (param_1 != (int *)0x0) {
    puVar1 = (uint *)(param_2 + 0x104);
    DAT_00955874 = 2;
    puVar5 = (undefined4 *)(param_2 + 0x5120);
    *puVar1 = *puVar1 + 3 & 0xfffffffc;
    param_1 = param_1 + 0x12;
    iVar3 = 9;
    do {
      if ((*param_1 < 1) || (*(int *)param_1[-0x12] == 0)) {
        *puVar5 = 0;
      }
      else {
        _Dst = (void *)*puVar1;
        *puVar5 = _Dst;
        local_188 = *param_1 << 5;
        _memset(_Dst,0,local_188);
        *puVar1 = *puVar1 + local_188;
      }
      param_1 = param_1 + 1;
      puVar5 = puVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (DAT_009553cc == 0) {
      local_19c = 0;
    }
    else {
      local_19c = FUN_004fd9f0("chars\\weirdo\\all_textures.fpk",puVar1,
                               *(undefined4 *)(local_1a0 + 0x108),0x20);
    }
    piVar6 = local_194;
    local_198 = (int *)(local_1a0 + 0x5144);
    local_194 = (int *)0x9;
    do {
      piVar4 = (int *)local_198[-9];
      *local_198 = 0;
      if (piVar4 != (int *)0x0) {
        if (((DAT_00804ec4 != 0) && (*(char *)(*piVar6 + 4) != '\0')) &&
           (iVar3 = *(int *)(*piVar6 + 8), iVar3 != 0)) {
          iVar3 = FUN_005ef7f0(puVar1,*(undefined4 *)(local_1a0 + 0x108),iVar3);
          *local_198 = iVar3;
          FUN_005925c0(*(undefined4 *)(*piVar6 + 8));
        }
        iVar3 = 0;
        local_18c = 0;
        if (0 < piVar6[0x12]) {
          do {
            FUN_004f1f10(local_104,*(undefined4 *)(iVar3 + piVar6[9]));
            FUN_004f1f10(local_184,"chars\\weirdo\\");
            FUN_004f1e80(local_184,*(undefined4 *)*piVar6);
            FUN_004f1e80(local_184,&DAT_0075a204);
            FUN_004f1e80(local_184,local_104);
            if (*(char *)(*piVar6 + 4) == '\0') {
              if (*(char *)(*piVar6 + 5) != -1) {
                FUN_004f1e80(local_184,&DAT_0075eac4);
                if (local_19c != 0) {
                  FUN_004f7cf0(local_84,local_184,0x80);
                  iVar2 = FUN_004f9de0(local_19c,local_84);
                  if ((iVar2 != -1) &&
                     (iVar2 = FUN_004f0f30(local_19c,iVar2,&local_190,&local_188), iVar2 != 0)) {
                    local_190 = FUN_004f4f40(local_190);
                    iVar2 = FUN_005e5210(local_190);
                    piVar4[5] = iVar2;
                    FUN_005925c0(local_184);
                  }
                }
                if (piVar4[5] == 0) {
                  iVar2 = FUN_005f8d60(local_184,puVar1,*(undefined4 *)(local_1a0 + 0x108));
                  piVar4[5] = iVar2;
                  FUN_005925c0(local_184);
                }
              }
            }
            else {
              if (*local_198 == 0) {
                FUN_004f1e80(local_184,&DAT_0075a1fc);
                *puVar1 = *puVar1 + 0x3f & 0xffffffc0;
                iVar2 = FUN_005ef7f0(puVar1,*(undefined4 *)(local_1a0 + 0x108),local_184);
                *piVar4 = iVar2;
                FUN_005925c0(local_184);
              }
              else {
                *piVar4 = *local_198;
              }
              if (*piVar4 != 0) {
                FUN_005cf5b0(*piVar4,piVar4 + 1,local_104,1);
              }
            }
            local_18c = local_18c + 1;
            iVar3 = iVar3 + 0x28;
            piVar4 = piVar4 + 8;
          } while (local_18c < piVar6[0x12]);
        }
      }
      local_198 = local_198 + 1;
      piVar6 = piVar6 + 1;
      local_194 = (int *)((int)local_194 + -1);
    } while (local_194 != (int *)0x0);
    local_194 = (int *)0x0;
  }
  __security_check_cookie(local_4 ^ (uint)&local_1a0);
  return;
}


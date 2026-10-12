/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da100; label: FUN_005da100
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005da100(undefined2 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *unaff_ESI;
  int iVar7;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  iVar5 = FUN_005d9140();
  *(undefined2 *)(iVar5 + 0x9e) = param_1;
  iVar6 = 0;
  local_18 = _DAT_0095fba8;
  local_14 = _DAT_0095fbac;
  local_10 = _DAT_0095fbb0;
  fVar4 = unaff_ESI[1] * _DAT_0095fbac;
  fVar2 = *unaff_ESI * _DAT_0095fba8;
  fVar3 = _DAT_0095fbb0 * unaff_ESI[2];
  fVar1 = unaff_ESI[3];
  if (0 < *(short *)(unaff_ESI + 5)) {
    iVar7 = 0;
    _param_1 = 0;
    do {
      FUN_005b3800(&local_24,&local_18,(int)unaff_ESI[4] + _param_1);
      iVar6 = iVar6 + 1;
      FUN_005b3800(local_c,&local_18,
                   (int)unaff_ESI[4] + (iVar6 % (int)*(short *)(unaff_ESI + 5)) * 0xc);
      FUN_005b3920(&local_24,&local_24,local_c);
      FUN_005b3b30(&local_24,&local_24);
      if (0.0 <= fVar3 + fVar4 + fVar2 + fVar1) {
        *(float *)(iVar7 + *(int *)(iVar5 + 0x80)) = -local_24;
        *(float *)(*(int *)(iVar5 + 0x80) + 4 + iVar7) = -local_20;
        *(float *)(*(int *)(iVar5 + 0x80) + 8 + iVar7) = -local_1c;
        *(float *)(*(int *)(iVar5 + 0x80) + 0xc + iVar7) =
             local_1c * local_10 + local_24 * local_18 + local_20 * local_14;
      }
      else {
        *(float *)(iVar7 + *(int *)(iVar5 + 0x80)) = local_24;
        *(float *)(*(int *)(iVar5 + 0x80) + 4 + iVar7) = local_20;
        *(float *)(*(int *)(iVar5 + 0x80) + 8 + iVar7) = local_1c;
        *(float *)(*(int *)(iVar5 + 0x80) + 0xc + iVar7) =
             -(local_1c * local_10 + local_24 * local_18 + local_20 * local_14);
      }
      _param_1 = _param_1 + 0xc;
      iVar7 = iVar7 + 0x10;
    } while (iVar6 < *(short *)(unaff_ESI + 5));
  }
  FUN_005d9f50();
  FUN_005d9850();
  return;
}



void FUN_00749570(int *param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  char cVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  char **ppcVar9;
  int iVar10;
  undefined *puVar11;
  char *pcVar12;
  char *pcVar13;
  undefined4 uVar14;
  char local_a9 [5];
  int local_a4;
  char *local_a0 [4];
  int local_90;
  int local_8c;
  char *local_88 [5];
  char *local_74;
  char *local_70;
  char *local_6c;
  char *local_68;
  char *local_64 [4];
  char *local_54;
  undefined *local_44 [4];
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined *local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined *local_8;
  undefined *local_4;
  
  iVar7 = *(int *)(param_2 + 0x974);
  iVar10 = *param_1;
  local_a9[1] = 0;
  local_a9[2] = 0;
  local_a9[3] = 0;
  local_a9[4] = 0;
  local_88[1] = "FUNC_UVSET_0";
  local_88[2] = "FUNC_UVSET_1";
  local_88[3] = "FUNC_UVSET_2";
  local_88[4] = "FUNC_UVSET_3";
  local_a0[0] = "varying_uvSet0";
  local_a0[1] = "varying_uvSet1";
  local_a0[2] = "varying_uvSet2";
  local_a0[3] = "varying_uvSet3";
  local_74 = "vs_uvSet0";
  local_70 = "vs_uvSet1";
  local_6c = "vs_uvSet2";
  local_68 = "vs_uvSet3";
  local_64[0] = "DISABLE";
  local_64[1] = "COMBINE_OVER";
  local_64[2] = "COMBINE_ADD";
  local_64[3] = "COMBINE_SUBTRACT";
  local_54 = "COMBINE_MULTIPLY";
  local_44[0] = &DAT_00771d80;
  local_44[1] = &DAT_00763618;
  local_44[2] = &DAT_00771da0;
  local_44[3] = &DAT_00771d9c;
  local_34 = &DAT_00771d98;
  local_30 = &DAT_00771d94;
  local_2c = &DAT_00771d90;
  local_28 = &DAT_00771d8c;
  local_24 = &DAT_00771d88;
  local_20 = &DAT_00771d84;
  local_1c = &DAT_007e9fdc;
  local_18 = &DAT_007e9fd8;
  local_14 = &DAT_007e9fd4;
  local_10 = &DAT_007e9fd0;
  local_c = &DAT_007e9fcc;
  local_8 = &DAT_007e9fc8;
  local_4 = &DAT_007e9fc4;
  local_a4 = iVar7;
  local_8c = iVar10;
  if (iVar7 == 4) {
    FUN_00747320("VERTEX_SHADER_VERSION",&DAT_007e9fc0,0);
    puVar11 = &DAT_007e9fc0;
  }
  else if (iVar7 == 3) {
    FUN_00747320("VERTEX_SHADER_VERSION",&DAT_007e9fa4,0);
    puVar11 = &DAT_007e9fa4;
  }
  else if (iVar7 == 2) {
    FUN_00747320("VERTEX_SHADER_VERSION",&DAT_007e9fa0,0);
    puVar11 = &DAT_007e9fa0;
  }
  else if (iVar7 == 1) {
    FUN_00747320("VERTEX_SHADER_VERSION",&DAT_007e9fd8,0);
    puVar11 = &DAT_007e9fd8;
  }
  else {
    FUN_00747320("VERTEX_SHADER_VERSION",&DAT_00771d80,0);
    puVar11 = &DAT_00771d80;
  }
  FUN_00747320("PIXEL_SHADER_VERSION",puVar11,0);
  FUN_00747320("BUILD_EFFECT",0,0);
  if ((iVar7 == 4) && (DAT_02976b94 == 0x10de)) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if (param_1[3] == 0) {
    if ((*(uint *)(*param_1 + 0x1b8) >> 0xe & 1) != 0) {
      pcVar12 = local_88[*(byte *)(iVar10 + 0xae)];
      local_a9[*(byte *)(iVar10 + 0xae)] = '\x01';
      FUN_00747320(pcVar12,"UVSET_ANIMATION",0);
      FUN_00747320("VTF_NORMAL_UVSET",local_a0[*(byte *)(iVar10 + 0xae) - 1],1);
      FUN_00747320("FUNC_fs_computeVTFNormal","VTF_SURFACE_NORMAL_MAP",0);
    }
    if ((param_1[3] == 0) && ((*(uint *)(*param_1 + 0x1b8) >> 0x1e & 1) != 0)) {
      FUN_00747320(&DAT_00755d68,0,0);
    }
  }
  if (bVar4) {
    uVar6 = *(uint *)(*param_1 + 0x1b8);
    if (((uVar6 >> 0x16 & 1) != 0) && ((*(uint *)(*param_1 + 0x13c) >> 0x19 & 1) != 0)) {
      if ((param_1[3] == 0) && ((uVar6 >> 0x12 & 1) != 0)) {
        pcVar12 = "VERTEX_TRANSFORM_PLANT2";
      }
      else {
        pcVar12 = "VERTEX_TRANSFORM_PLANT";
      }
      FUN_00747320("FUNC_pipePosition",pcVar12,0);
      FUN_00747320(&DAT_007e9ed4,0,0);
    }
    if (((*(byte *)(*param_1 + 0x1bc) & 1) != 0) && ((*(uint *)(*param_1 + 0x13c) >> 0x19 & 1) != 0)
       ) {
      FUN_00747320("FUNC_pipePosition","VERTEX_TRANSFORM_PLANT2",0);
      FUN_00747320(&DAT_007e9ed4,0,0);
    }
    if (((*(uint *)(*param_1 + 0x1bc) >> 1 & 1) != 0) &&
       ((*(uint *)(*param_1 + 0x13c) >> 0x19 & 1) != 0)) {
      FUN_00747320(&DAT_007e9ed4,0,0);
    }
    if ((param_1[3] != 0) || ((*(uint *)(*param_1 + 0x1b8) >> 0xd & 1) == 0)) goto LAB_00749961;
    pcVar12 = local_88[*(byte *)(iVar10 + 0xae)];
    local_a9[*(byte *)(iVar10 + 0xae)] = '\x01';
    FUN_00747320(pcVar12,"UVSET_ANIMATION",0);
    FUN_00747320("VERTEX_FETCH_UVSET",local_88[*(byte *)(iVar10 + 0xae) + 4],1);
    pcVar13 = "VERTEX_FETCH_DISPLACEMENT";
    pcVar12 = "FUNC_pipePosition";
LAB_00749a45:
    FUN_00747320(pcVar12,pcVar13,0);
  }
  else {
LAB_00749961:
    if (param_1[3] == 0) {
      if ((((*(uint *)(*param_1 + 0x1b8) >> 0x1d & 1) == 0) ||
          (uVar6 = *(uint *)(*param_1 + 0x13c), (uVar6 & 0x30000) == 0)) ||
         ((uVar6 & 0x400000) != 0)) {
        if ((*(uint *)(*param_1 + 0x1b8) >> 0x1d & 1) == 0) {
          if ((*(uint *)(*param_1 + 0x1b8) >> 9 & 1) == 0) goto LAB_007499df;
          pcVar13 = "VERTEX_TRANSFORM_WATER";
          pcVar12 = "FUNC_pipePosition";
        }
        else {
          pcVar13 = "VERTEX_TRANSFORM_REFRACTED_GLASS";
          pcVar12 = "FUNC_pipePosition";
        }
      }
      else {
        pcVar12 = "VERTEX_TRANSFORM_REFRACTED_GLASS_SKINNING";
LAB_00749a1a:
        FUN_00747320("FUNC_pipePosition",pcVar12,0);
        FUN_00747320("FUNC_computeNormal","VERTEX_TRANSFORM_SKINNING",0);
        pcVar13 = "VERTEX_TRANSFORM_SKINNING";
        pcVar12 = "FUNC_computeTangent";
      }
      goto LAB_00749a45;
    }
LAB_007499df:
    if ((*(uint *)(*param_1 + 0x13c) >> 0x12 & 1) != 0) {
      pcVar13 = "VERTEX_RAW";
      pcVar12 = "FUNC_pipePosition";
      goto LAB_00749a45;
    }
    cVar5 = FUN_00744230();
    if ((cVar5 != '\0') || (cVar5 = FUN_00744250(), cVar5 != '\0')) {
      pcVar12 = "VERTEX_TRANSFORM_SKINNING";
      goto LAB_00749a1a;
    }
  }
  if ((*(uint *)(*param_1 + 0x13c) >> 0x13 & 1) != 0) {
    FUN_00747320("VERTEX_GROUP",0,0);
  }
  if ((*(byte *)(*param_1 + 0x13f) & 1) != 0) {
    FUN_00747320("FUNC_WATERCOEF","WATERCOEF_AMPLITUDE",1);
  }
  if (param_1[3] == 0) {
    if ((*(uint *)(*param_1 + 0x1b8) >> 1 & 1) == 0) {
      if ((*(uint *)(*param_1 + 0x1b8) & 1) == 0) goto LAB_00749b00;
      pcVar12 = local_a0[*(byte *)(iVar10 + 0xa9) - 1];
      local_a9[*(byte *)(iVar10 + 0xa9)] = '\x01';
      FUN_00747320("SURFACE_UVSET",pcVar12,1);
      pcVar12 = "SURFACE_NORMAL_MAP";
    }
    else {
      bVar1 = *(byte *)(iVar10 + 0xa9);
      local_a9[bVar1] = '\x01';
      FUN_00747320("SURFACE_UVSET",local_a0[bVar1 - 1],1);
      pcVar12 = "SURFACE_PARALLAX_MAP";
    }
  }
  else {
LAB_00749b00:
    pcVar12 = "SURFACE_SMOOTH";
  }
  FUN_00747320("SURFACE_TYPE",pcVar12,0);
  if (param_1[3] == 0) {
    if (((*(uint *)(*param_1 + 0x1b8) >> 1 & 1) == 0) || (*(int *)(*param_1 + 0x38) <= param_1[8]))
    {
      if (((*(uint *)(*param_1 + 0x1b8) & 1) == 0) || (*(int *)(*param_1 + 0x38) <= param_1[8]))
      goto LAB_00749b79;
      pcVar12 = "SURFACE_NORMAL_MAP";
    }
    else {
      pcVar12 = "SURFACE_PARALLAX_MAP";
    }
    FUN_00747320("SURFACE_TYPE2",pcVar12,0);
    pcVar12 = local_a0[*(byte *)(iVar10 + 0xab) - 1];
    uVar14 = 1;
    pcVar13 = "LAYER1_UVSET";
  }
  else {
LAB_00749b79:
    uVar14 = 0;
    pcVar12 = "SURFACE_SMOOTH";
    pcVar13 = "SURFACE_TYPE2";
  }
  FUN_00747320(pcVar13,pcVar12,uVar14);
  if (((param_1[3] == 0) || (*(char *)(*param_1 + 0x1b4) != '\0')) &&
     ((*(uint *)(*param_1 + 0x13c) & 0x100) != 0)) {
    FUN_00747320("LAYER0_COLORSET",&DAT_00771d80,0);
  }
  cVar5 = FUN_007445b0(0);
  if (cVar5 != '\0') {
    FUN_00747320("COMBINE_OP_0","COMBINE_BASE",0);
    cVar5 = FUN_007444b0(0);
    if (cVar5 == '\0') {
      pcVar12 = "LAYER0_DIFFUSEENABLE";
    }
    else {
      FUN_00747320("LAYER0_UVSET","varying_uvSet0",1);
      local_a9[1] = 1;
      if ((*(int *)(*param_1 + 0x1e4) < 1) || (*(int *)(*param_1 + 0x1e8) < 1)) goto LAB_00749c34;
      pcVar12 = "TEXTURE_ANIMATION_MAP";
    }
    FUN_00747320(pcVar12,0,0);
  }
LAB_00749c34:
  cVar5 = FUN_007445b0(1);
  iVar7 = local_a4;
  if ((cVar5 != '\0') && (local_a4 != 1)) {
    FUN_00747320("COMBINE_OP_1",local_64[*(byte *)(iVar10 + 0x44)],1);
    if (((param_1[3] == 0) || (*(char *)(*param_1 + 0x1b4) != '\0')) &&
       ((*(uint *)(*param_1 + 0x13c) >> 9 & 3) != 0)) {
      FUN_00747320("LAYER1_ALPHA",0,0);
      FUN_00747320("LAYER1_COLORSET","varying_colorSet1",1);
    }
    cVar5 = FUN_007444b0(1);
    if (cVar5 == '\0') {
      FUN_00747320("LAYER1_DIFFUSEENABLE",0,0);
    }
    else {
      FUN_00747320("LAYER1_UVSET",local_a0[*(byte *)(iVar10 + 0xab) - 1],1);
      local_a9[*(byte *)(iVar10 + 0xab)] = '\x01';
    }
  }
  cVar5 = FUN_007445b0(2);
  if ((cVar5 != '\0') && (iVar7 != 1)) {
    FUN_00747320("COMBINE_OP_2",local_64[*(byte *)(iVar10 + 0x45)],1);
    if (((param_1[3] == 0) || (*(char *)(*param_1 + 0x1b4) != '\0')) &&
       (1 < ((byte)(*(uint *)(*param_1 + 0x13c) >> 9) & 3))) {
      FUN_00747320("LAYER2_ALPHA",0,0);
      FUN_00747320("LAYER1_COLORSET","varying_colorSet1",1);
    }
    cVar5 = FUN_007444b0(2);
    if (cVar5 == '\0') {
      FUN_00747320("LAYER2_DIFFUSEENABLE",0,0);
    }
    else {
      FUN_00747320("LAYER2_UVSET",local_a0[*(byte *)(iVar10 + 0xac) - 1],1);
      local_a9[*(byte *)(iVar10 + 0xac)] = '\x01';
    }
  }
  cVar5 = FUN_007445b0(3);
  if ((cVar5 != '\0') && (iVar7 != 1)) {
    FUN_00747320("COMBINE_OP_3",local_64[*(byte *)(iVar10 + 0x46)],1);
    if (((param_1[3] == 0) || (*(char *)(*param_1 + 0x1b4) != '\0')) &&
       (2 < ((byte)(*(uint *)(*param_1 + 0x13c) >> 9) & 3))) {
      FUN_00747320("LAYER3_ALPHA",0,0);
      FUN_00747320("LAYER1_COLORSET","varying_colorSet1",1);
    }
    cVar5 = FUN_007444b0(3);
    if (cVar5 == '\0') {
      FUN_00747320("LAYER3_DIFFUSEENABLE",0,0);
    }
    else {
      FUN_00747320("LAYER3_UVSET",local_a0[*(byte *)(iVar10 + 0xad) - 1],1);
      local_a9[*(byte *)(iVar10 + 0xad)] = '\x01';
    }
  }
  if (param_1[3] != 0) {
LAB_0074a01a:
    pcVar12 = "DISABLE";
    goto LAB_0074a021;
  }
  uVar6 = *(uint *)(*param_1 + 0x1b8);
  if ((uVar6 & 0x1000) == 0) {
    if ((uVar6 >> 0x11 & 1) != 0) {
      pcVar12 = "LIGHTING_GOOCH";
LAB_0074a021:
      pcVar13 = "LIGHTING_STAGE";
LAB_0074a028:
      FUN_00747320(pcVar13,pcVar12,0);
      goto LAB_0074a02d;
    }
    if ((uVar6 >> 0x13 & 1) != 0) {
      pcVar12 = "LIGHTING_ENVMAP";
      goto LAB_0074a021;
    }
    if ((uVar6 >> 4 & 1) == 0) goto LAB_00749f0f;
    FUN_00747320("LIGHTING_STAGE","LIGHTING_ANISO",0);
    if (param_1[3] == 0) {
      if ((*(uint *)(*param_1 + 0x1b8) >> 0x19 & 1) == 0) goto LAB_0074a02d;
      pcVar12 = (char *)0x0;
      pcVar13 = "ANISO_FLIP";
      goto LAB_0074a028;
    }
  }
  else {
    if (-1 < *(int *)(*param_1 + 0x1b8)) goto LAB_0074a01a;
    FUN_00747320("PRELIGHT_FX",0,0);
    if ((param_1[3] == 0) &&
       (((*(uint *)(*param_1 + 0x1b8) >> 3 & 1) != 0 ||
        ((*(uint *)(*param_1 + 0x1b8) >> 4 & 1) != 0)))) {
      FUN_00747320("PRELIGHT_FX_LIVE_SPECULAR",0,0);
    }
    if (param_1[3] != 0) {
LAB_00749f0f:
      cVar5 = FUN_007488d0();
      if (cVar5 == '\0') {
        pcVar12 = "LIGHTING_LAMBERT";
        pcVar13 = "LIGHTING_STAGE";
      }
      else {
        pcVar12 = "LIGHTING_PHONG";
        pcVar13 = "LIGHTING_STAGE";
      }
      goto LAB_0074a028;
    }
    iVar2 = *param_1;
    if (((*(uint *)(iVar2 + 0x1b8) >> 0x11 & 1) != 0) ||
       ((*(uint *)(iVar2 + 0x1b8) >> 0x13 & 1) != 0)) goto LAB_0074a01a;
    if ((*(uint *)(iVar2 + 0x1b8) >> 4 & 1) == 0) goto LAB_00749f0f;
    FUN_00747320("LIGHTING_STAGE","LIGHTING_ANISO",0);
    cVar5 = FUN_007487e0();
    if (cVar5 != '\0') {
      pcVar12 = (char *)0x0;
      pcVar13 = "ANISO_FLIP";
      goto LAB_0074a028;
    }
LAB_0074a02d:
    if (param_1[3] == 0) {
      uVar6 = ((uint *)*param_1)[0x6e];
      if ((((uVar6 >> 0x12 & 1) != 0) && ((uVar6 >> 0x16 & 1) == 0)) &&
         ((uVar6 = *(uint *)*param_1, -1 < (int)uVar6 || ((uVar6 & 0x800000) == 0)))) {
        FUN_00747320("CAR_PAINT",0,0);
      }
    }
  }
  FUN_00747320("LIGHTING_LIGHTS_COUNT",&DAT_00771d9c,0);
  if ((param_1[3] == 0) &&
     (((((int)*(uint *)*param_1 < 0 && ((*(uint *)*param_1 & 0x800000) != 0)) ||
       (((int)*(uint *)*param_1 < 0 && ((*(uint *)*param_1 & 0x800000) == 0)))) &&
      (bVar1 = *(byte *)(iVar10 + 0xa8), bVar1 != 0)))) {
    if (iVar7 == 1) {
      uVar6 = *(uint *)(iVar10 + 0x1bc) >> 2 & 3;
      if (uVar6 == 0) {
        FUN_00747320("LIGHTMAP_UVSET",local_a0[bVar1 - 1],1);
        local_a9[*(byte *)(iVar10 + 0xa8)] = '\x01';
      }
      else {
        FUN_00747320("LIGHTMAP_UVSET",local_a0[uVar6],1);
        local_a9[(*(uint *)(iVar10 + 0x1bc) >> 2 & 3) + 1] = '\x01';
      }
    }
    else {
      FUN_00747320("LIGHTMAP_UVSET",local_a0[bVar1 - 1],1);
    }
    if ((DAT_008264c7 == '\0') ||
       (((param_1[3] == 0 && ((int)*(uint *)*param_1 < 0)) && ((*(uint *)*param_1 & 0x800000) != 0))
       )) {
      pcVar12 = "LIGHTMAP_SMOOTH";
    }
    else {
      pcVar12 = "LIGHTMAP_DIRECTIONAL";
    }
  }
  else {
    pcVar12 = "DISABLE";
  }
  FUN_00747320("LIGHTMAP_STAGE",pcVar12,0);
  local_a9[0] = '\0';
  if (param_1[3] == 0) {
    if (((*(uint *)(*param_1 + 0x1b8) >> 5 & 1) == 0) &&
       ((((*(uint *)(*param_1 + 0x1b8) >> 0x1e & 1) == 0 &&
         ((*(uint *)(*param_1 + 0x1b8) >> 0x1d & 1) == 0)) || (iVar7 == 1)))) {
      if ((*(uint *)(*param_1 + 0x1b8) >> 0xf & 1) == 0) {
        if (((*(uint *)(*param_1 + 0x1b8) >> 5 & 1) == 0) ||
           ((*(uint *)(*param_1 + 0x1b8) >> 0xf & 1) == 0)) goto LAB_0074a271;
        pcVar13 = "ENVMAP_SPHERE";
        local_a9[0] = '\x01';
        pcVar12 = "ENVMAP_STAGE";
      }
      else {
        pcVar13 = "PS2_SHINEMAP";
        local_a9[0] = '\x01';
        pcVar12 = "ENVMAP_STAGE";
      }
    }
    else {
      local_a9[0] = '\x01';
      FUN_00747320("ENVMAP_STAGE","ENVMAP_CUBE",0);
      if (((param_1[3] != 0) || ((*(uint *)(*param_1 + 0x1b8) >> 0x1d & 1) == 0)) || (iVar7 == 1))
      goto LAB_0074a271;
      pcVar13 = "SPECULAR_PHONG";
      pcVar12 = "SPECULAR_STAGE";
    }
    FUN_00747320(pcVar12,pcVar13,0);
  }
LAB_0074a271:
  if ((param_1[3] == 0) &&
     (((*(uint *)(*param_1 + 0x1b8) >> 3 & 1) != 0 || ((*(uint *)(*param_1 + 0x1b8) >> 4 & 1) != 0))
     )) {
    bVar4 = true;
  }
  else {
    bVar4 = false;
  }
  if ((local_a9[0] != '\0') || (bVar4)) {
    if (local_a4 != 1) {
      FUN_00747320("REFLECTIVITY_STAGE",0,0);
    }
    if ((param_1[3] == 0) && (param_1[8] < *(int *)(*param_1 + 0x48))) {
      FUN_00747320("SPECULAR_UVSET",local_a0[*(byte *)(iVar10 + 0xaa) - 1],1);
      local_a9[1] = 1;
    }
    else {
      FUN_00747320("SPECULAR_SPECULARENABLE",0,0);
    }
    if (param_1[3] == 0) {
      if (((*(uint *)(*param_1 + 0x1b8) >> 0x14 & 1) == 0) ||
         (*(int *)(*param_1 + 0x34) <= param_1[8])) {
        if (((*(uint *)(*param_1 + 0x1b8) >> 0x14 & 1) == 0) ||
           (param_1[8] < *(int *)(*param_1 + 0x34))) goto LAB_0074a38c;
        FUN_00747320("REFLECTIVITY_STAGE2",0,0);
        uVar14 = 0;
        pcVar12 = (char *)0x0;
        pcVar13 = "SPECULAR_SPECULARENABLE2";
      }
      else {
        FUN_00747320("REFLECTIVITY_STAGE2",0,0);
        pcVar12 = local_a0[*(byte *)(iVar10 + 0xab) - 1];
        uVar14 = 1;
        pcVar13 = "LAYER1_UVSET";
      }
      FUN_00747320(pcVar13,pcVar12,uVar14);
    }
LAB_0074a38c:
    if ((local_a9[0] == '\0') && (!bVar4)) goto LAB_0074a397;
LAB_0074a3b1:
    if (param_1[3] == 0) {
      if ((*(uint *)(*param_1 + 0x1b8) >> 2 & 1) != 0) {
        FUN_00747320("FRESNEL_STAGE",0,0);
      }
LAB_0074a3d7:
      if ((param_1[3] == 0) && (uVar6 = *(uint *)(*param_1 + 0x1b8), (uVar6 >> 10 & 1) != 0)) {
        if ((uVar6 >> 9 & 1) == 0) {
          if ((uVar6 >> 0x1d & 1) == 0) {
            pcVar12 = "REFRACTION_DEFAULT";
          }
          else {
            pcVar12 = "REFRACTION_GLASS";
          }
        }
        else {
          pcVar12 = "REFRACTION_WATER";
        }
        FUN_00747320("REFRACTION_STAGE",pcVar12,0);
      }
    }
  }
  else {
LAB_0074a397:
    if (param_1[3] == 0) {
      if ((*(uint *)(*param_1 + 0x1b8) >> 10 & 1) != 0) goto LAB_0074a3b1;
      goto LAB_0074a3d7;
    }
  }
  iVar10 = 1;
  iVar7 = 0;
  pcVar12 = local_a9;
  ppcVar9 = local_88;
  local_88[0] = pcVar12;
  local_90 = 4;
  do {
    ppcVar9 = ppcVar9 + 1;
    if (pcVar12[iVar10] != '\0') {
      FUN_00747320(*ppcVar9,"UVSET_ANIMATION",0);
      iVar7 = iVar10;
      pcVar12 = local_88[0];
    }
    iVar10 = iVar10 + 1;
    local_90 = local_90 + -1;
  } while (local_90 != 0);
  FUN_00747320("UVSET_COUNT",local_44[iVar7],0);
  FUN_00747320("NUMTCs",local_44[*(byte *)(local_8c + 0xa8)],0);
  if (param_1[4] != 0) {
    FUN_00747320("NORMAL_OUTPUT",&DAT_00763618,1);
    puVar3 = (uint *)*param_1;
    if (((puVar3[0x4f] & 0xc) != 0) &&
       ((param_1[3] != 0 ||
        ((((-1 < (int)*puVar3 || ((*puVar3 & 0x800000) == 0)) &&
          ((-1 < (int)*puVar3 || ((*puVar3 & 0x800000) != 0)))) && (-1 < (int)puVar3[0x6e])))))) {
      FUN_00747320("NORMAL_OUTPUT_NOT_NULL",0,0);
    }
  }
  if ((param_1[3] == 0) && ((*(byte *)(*param_1 + 0x1ba) & 1) != 0)) {
    FUN_00747320("GLOW_OUTPUT",&DAT_00763618,1);
  }
  if (param_1[5] != 0) {
    FUN_00747320("MOTION_OUTPUT",&DAT_00771da0,1);
  }
  if (param_1[6] != 0) {
    if (param_1[3] == 0) {
      if (param_1[5] == 0) {
        puVar11 = &DAT_00771da0;
      }
      else {
        puVar11 = &DAT_00771d9c;
      }
    }
    else {
      puVar11 = &DAT_00771d80;
    }
    FUN_00747320("DEPTHRT_OUTPUT",puVar11,1);
  }
  if (param_1[3] != 0) {
    FUN_00747320("RENDER_FOR_SHADOW",0,0);
  }
  iVar7 = param_1[7];
  bVar4 = true;
  if (iVar7 < 1) {
    iVar7 = 1;
  }
  FUN_00747320("RENDER_TARGET_COUNT",local_44[iVar7],1);
  if (param_1[5] != 0) {
    uVar6 = *(uint *)(*param_1 + 0x13c);
    uVar8 = uVar6 >> 0x10 & 1;
    if ((((uVar8 != 0) || ((uVar6 & 0x20000) != 0)) && ((uVar6 & 0x400000) == 0)) ||
       (((uVar8 != 0 || ((uVar6 & 0x20000) != 0)) && ((uVar6 & 0x400000) != 0)))) {
      FUN_00747320("HACK_MOTION_VECTOR_NULL",0,0);
    }
  }
  FUN_00747320("COLOR_FACTOR",&DAT_007e9908,1);
  if ((*(uint *)(*param_1 + 0x13c) >> 0x12 & 1) == 0) {
    if (param_1[3] != 0) goto LAB_0074a6ba;
    if (local_a4 != 1) {
      FUN_00747320("FOG_STAGE","FOG_VERTEX_CLAMP_EXPONENTIAL2",0);
    }
  }
  if (param_1[3] == 0) {
    if (((*(uint *)(*param_1 + 0x1b8) >> 0x15 & 1) != 0) && (local_a4 != 1)) {
      FUN_00747320("DAPPLE",0,0);
    }
    if (param_1[3] == 0) {
      if ((*(uint *)(*param_1 + 0x1b8) >> 0x1c & 1) != 0) {
        FUN_00747320("FRACTAL",0,0);
      }
      if ((param_1[3] == 0) && ((*(uint *)(*param_1 + 0x1b8) >> 0x1b & 1) != 0)) {
        FUN_00747320("EDGE_LIGHTING",0,0);
      }
    }
  }
LAB_0074a6ba:
  iVar7 = param_1[1];
  if ((((iVar7 != 0) && (*(int *)(iVar7 + 0x100) != 0)) &&
      (iVar7 = FUN_005e5310(*(undefined4 *)(iVar7 + 0x100)), iVar7 != 0)) &&
     ((*(int *)(iVar7 + 0x24) != 0 &&
      ((**(code **)(**(int **)(iVar7 + 0x24) + 0x44))(*(int **)(iVar7 + 0x24),0,local_64),
      local_64[0] == (char *)0x31545844)))) {
    bVar4 = false;
  }
  FUN_00747320("_WINPC",0,0);
  if (bVar4) {
    FUN_00747320("SWIZZLE_NORMAL_MAPS",0,0);
  }
  FUN_00747320("SWIZZLE_PARALLAX_MAPS",0,0);
  FUN_00747320("PACKED_NORMAL",0,0);
  FUN_00747320("PACKED_TANGENT",0,0);
  FUN_00747320("PACKED_TANGENT2",0,0);
  FUN_00747320("PACKED_VECTOR",0,0);
  FUN_00747320("SKIN_WORLD",0,0);
  return;
}


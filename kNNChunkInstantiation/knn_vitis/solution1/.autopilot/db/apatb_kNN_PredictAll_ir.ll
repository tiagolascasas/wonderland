; ModuleID = 'C:/Users/Tiago/Dev/Experiments/kNNChunkInstantiation/knn_vitis/solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: inaccessiblememonly nounwind
declare void @llvm.sideeffect() #0

; Function Attrs: noinline
define void @apatb_kNN_PredictAll_ir([43 x float]* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4336" %training_X, i8* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="4336" %training_Y, [43 x float]* noalias nocapture nonnull "fpga.decayed.dim.hint"="1082" %testing_X, i8* noalias nocapture nonnull "fpga.decayed.dim.hint"="1082" %testing_Y, float* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="43" %min, float* noalias nocapture nonnull readonly "fpga.decayed.dim.hint"="43" %max) local_unnamed_addr #1 {
entry:
  %malloccall_0 = call i8* @malloc(i64 186448)
  %malloccall_1 = call i8* @malloc(i64 186448)
  %malloccall_2 = call i8* @malloc(i64 186448)
  %malloccall_3 = call i8* @malloc(i64 186448)
  %training_X_copy_0 = bitcast i8* %malloccall_0 to [1084 x [43 x float]]*
  %training_X_copy_1 = bitcast i8* %malloccall_1 to [1084 x [43 x float]]*
  %training_X_copy_2 = bitcast i8* %malloccall_2 to [1084 x [43 x float]]*
  %training_X_copy_3 = bitcast i8* %malloccall_3 to [1084 x [43 x float]]*
  %malloccall1 = tail call i8* @malloc(i64 4336)
  %training_Y_copy = bitcast i8* %malloccall1 to [4336 x i8]*
  %malloccall2 = tail call i8* @malloc(i64 186104)
  %testing_X_copy = bitcast i8* %malloccall2 to [1082 x [43 x float]]*
  %testing_Y_copy = alloca [1082 x i8], align 512
  %min_copy = alloca [43 x float], align 512
  %max_copy = alloca [43 x float], align 512
  %0 = bitcast [43 x float]* %training_X to [4336 x [43 x float]]*
  %1 = bitcast i8* %training_Y to [4336 x i8]*
  %2 = bitcast [43 x float]* %testing_X to [1082 x [43 x float]]*
  %3 = bitcast i8* %testing_Y to [1082 x i8]*
  %4 = bitcast float* %min to [43 x float]*
  %5 = bitcast float* %max to [43 x float]*
  call void @copy_in([4336 x [43 x float]]* nonnull %0, [1084 x [43 x float]]* %training_X_copy_0, [1084 x [43 x float]]* %training_X_copy_1, [1084 x [43 x float]]* %training_X_copy_2, [1084 x [43 x float]]* %training_X_copy_3, [4336 x i8]* nonnull %1, [4336 x i8]* %training_Y_copy, [1082 x [43 x float]]* nonnull %2, [1082 x [43 x float]]* %testing_X_copy, [1082 x i8]* nonnull %3, [1082 x i8]* nonnull align 512 %testing_Y_copy, [43 x float]* nonnull %4, [43 x float]* nonnull align 512 %min_copy, [43 x float]* nonnull %5, [43 x float]* nonnull align 512 %max_copy)
  %_0 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %training_X_copy_0, i32 0, i32 0
  %_1 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %training_X_copy_1, i32 0, i32 0
  %_2 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %training_X_copy_2, i32 0, i32 0
  %_3 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %training_X_copy_3, i32 0, i32 0
  %6 = getelementptr inbounds [1082 x [43 x float]], [1082 x [43 x float]]* %testing_X_copy, i32 0, i32 0
  %7 = getelementptr inbounds [1082 x i8], [1082 x i8]* %testing_Y_copy, i32 0, i32 0
  %8 = getelementptr inbounds [43 x float], [43 x float]* %min_copy, i32 0, i32 0
  %9 = getelementptr inbounds [43 x float], [43 x float]* %max_copy, i32 0, i32 0
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x float]* %_0, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x float]* %_1, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x float]* %_2, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @llvm.sideeffect() #0 [ "xlx_array_partition"([43 x float]* %_3, i32 0, i32 1, i32 0, i1 false) ], !dbg !5
  call void @apatb_kNN_PredictAll_hw([1084 x [43 x float]]* %training_X_copy_0, [1084 x [43 x float]]* %training_X_copy_1, [1084 x [43 x float]]* %training_X_copy_2, [1084 x [43 x float]]* %training_X_copy_3, i8* %malloccall1, [43 x float]* %6, i8* %7, float* %8, float* %9)
  call void @copy_back([4336 x [43 x float]]* %0, [1084 x [43 x float]]* %training_X_copy_0, [1084 x [43 x float]]* %training_X_copy_1, [1084 x [43 x float]]* %training_X_copy_2, [1084 x [43 x float]]* %training_X_copy_3, [4336 x i8]* %1, [4336 x i8]* %training_Y_copy, [1082 x [43 x float]]* %2, [1082 x [43 x float]]* %testing_X_copy, [1082 x i8]* %3, [1082 x i8]* %testing_Y_copy, [43 x float]* %4, [43 x float]* %min_copy, [43 x float]* %5, [43 x float]* %max_copy)
  call void @free(i8* %malloccall_0)
  call void @free(i8* %malloccall_1)
  call void @free(i8* %malloccall_2)
  call void @free(i8* %malloccall_3)
  tail call void @free(i8* %malloccall1)
  tail call void @free(i8* %malloccall2)
  ret void
}

declare noalias i8* @malloc(i64) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a4336i8([4336 x i8]* noalias, [4336 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [4336 x i8]* %0, null
  %3 = icmp eq [4336 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [4336 x i8], [4336 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [4336 x i8], [4336 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 4336
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a1082a43f32([1082 x [43 x float]]* noalias, [1082 x [43 x float]]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [1082 x [43 x float]]* %0, null
  %3 = icmp eq [1082 x [43 x float]]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  br label %for.loop2

for.loop2:                                        ; preds = %for.loop2, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %for.loop2 ]
  %dst.addr57 = getelementptr [1082 x [43 x float]], [1082 x [43 x float]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %src.addr68 = getelementptr [1082 x [43 x float]], [1082 x [43 x float]]* %1, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %5 = load float, float* %src.addr68, align 4
  store float %5, float* %dst.addr57, align 4
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 43
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %for.loop2
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 1082
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* noalias align 512, [1082 x i8]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [1082 x i8]* %0, null
  %3 = icmp eq [1082 x i8]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [1082 x i8], [1082 x i8]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [1082 x i8], [1082 x i8]* %1, i64 0, i64 %for.loop.idx1
  %5 = load i8, i8* %src.addr, align 1
  store i8 %5, i8* %dst.addr, align 1
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 1082
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal fastcc void @onebyonecpy_hls.p0a43f32([43 x float]* noalias align 512, [43 x float]* noalias readonly) unnamed_addr #2 {
entry:
  %2 = icmp eq [43 x float]* %0, null
  %3 = icmp eq [43 x float]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx1 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr = getelementptr [43 x float], [43 x float]* %0, i64 0, i64 %for.loop.idx1
  %src.addr = getelementptr [43 x float], [43 x float]* %1, i64 0, i64 %for.loop.idx1
  %5 = load float, float* %src.addr, align 4
  store float %5, float* %dst.addr, align 4
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx1, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 43
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

declare void @free(i8*) local_unnamed_addr

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a4336a43f32.77.78([1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_0, [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_1, [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_2, [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0" %_3, [4336 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1") #2 {
entry:
  %1 = icmp eq [1084 x [43 x float]]* %_0, null
  %2 = icmp eq [4336 x [43 x float]]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %4 = urem i64 %for.loop.idx10, 4
  %5 = udiv i64 %for.loop.idx10, 4
  %6 = trunc i64 %4 to i2
  br label %for.loop2

for.loop2:                                        ; preds = %dst.addr57.exit, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %dst.addr57.exit ]
  %dst.addr57_0 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_0, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_1 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_1, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_2 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_2, i64 0, i64 %5, i64 %for.loop.idx39
  %dst.addr57_3 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_3, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68 = getelementptr [4336 x [43 x float]], [4336 x [43 x float]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %7 = load float, float* %src.addr68, align 4
  switch i2 %6, label %dst.addr57.case.3 [
    i2 0, label %dst.addr57.case.0
    i2 1, label %dst.addr57.case.1
    i2 -2, label %dst.addr57.case.2
  ]

dst.addr57.case.0:                                ; preds = %for.loop2
  store float %7, float* %dst.addr57_0, align 4
  br label %dst.addr57.exit

dst.addr57.case.1:                                ; preds = %for.loop2
  store float %7, float* %dst.addr57_1, align 4
  br label %dst.addr57.exit

dst.addr57.case.2:                                ; preds = %for.loop2
  store float %7, float* %dst.addr57_2, align 4
  br label %dst.addr57.exit

dst.addr57.case.3:                                ; preds = %for.loop2
  store float %7, float* %dst.addr57_3, align 4
  br label %dst.addr57.exit

dst.addr57.exit:                                  ; preds = %dst.addr57.case.3, %dst.addr57.case.2, %dst.addr57.case.1, %dst.addr57.case.0
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 43
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %dst.addr57.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 4336
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_in([4336 x [43 x float]]* noalias readonly "orig.arg.no"="0", [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [1084 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4336 x i8]* noalias readonly "orig.arg.no"="2", [4336 x i8]* noalias "orig.arg.no"="3", [1082 x [43 x float]]* noalias readonly "orig.arg.no"="4", [1082 x [43 x float]]* noalias "orig.arg.no"="5", [1082 x i8]* noalias readonly "orig.arg.no"="6", [1082 x i8]* noalias align 512 "orig.arg.no"="7", [43 x float]* noalias readonly "orig.arg.no"="8", [43 x float]* noalias align 512 "orig.arg.no"="9", [43 x float]* noalias readonly "orig.arg.no"="10", [43 x float]* noalias align 512 "orig.arg.no"="11") #3 {
entry:
  call void @onebyonecpy_hls.p0a4336a43f32.77.78([1084 x [43 x float]]* %_0, [1084 x [43 x float]]* %_1, [1084 x [43 x float]]* %_2, [1084 x [43 x float]]* %_3, [4336 x [43 x float]]* %0)
  call fastcc void @onebyonecpy_hls.p0a4336i8([4336 x i8]* %2, [4336 x i8]* %1)
  call fastcc void @onebyonecpy_hls.p0a1082a43f32([1082 x [43 x float]]* %4, [1082 x [43 x float]]* %3)
  call fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* align 512 %6, [1082 x i8]* %5)
  call fastcc void @onebyonecpy_hls.p0a43f32([43 x float]* align 512 %8, [43 x float]* %7)
  call fastcc void @onebyonecpy_hls.p0a43f32([43 x float]* align 512 %10, [43 x float]* %9)
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @onebyonecpy_hls.p0a4336a43f32.85.86([4336 x [43 x float]]* noalias "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="0", [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3) #2 {
entry:
  %1 = icmp eq [4336 x [43 x float]]* %0, null
  %2 = icmp eq [1084 x [43 x float]]* %_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx10 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %4 = urem i64 %for.loop.idx10, 4
  %5 = udiv i64 %for.loop.idx10, 4
  %6 = trunc i64 %4 to i2
  br label %for.loop2

for.loop2:                                        ; preds = %src.addr68.exit, %for.loop
  %for.loop.idx39 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %src.addr68.exit ]
  %dst.addr57 = getelementptr [4336 x [43 x float]], [4336 x [43 x float]]* %0, i64 0, i64 %for.loop.idx10, i64 %for.loop.idx39
  %src.addr68_0 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_0, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_1 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_1, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_2 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_2, i64 0, i64 %5, i64 %for.loop.idx39
  %src.addr68_3 = getelementptr [1084 x [43 x float]], [1084 x [43 x float]]* %_3, i64 0, i64 %5, i64 %for.loop.idx39
  switch i2 %6, label %src.addr68.case.3 [
    i2 0, label %src.addr68.case.0
    i2 1, label %src.addr68.case.1
    i2 -2, label %src.addr68.case.2
  ]

src.addr68.case.0:                                ; preds = %for.loop2
  %_01 = load float, float* %src.addr68_0, align 4
  br label %src.addr68.exit

src.addr68.case.1:                                ; preds = %for.loop2
  %_12 = load float, float* %src.addr68_1, align 4
  br label %src.addr68.exit

src.addr68.case.2:                                ; preds = %for.loop2
  %_23 = load float, float* %src.addr68_2, align 4
  br label %src.addr68.exit

src.addr68.case.3:                                ; preds = %for.loop2
  %_34 = load float, float* %src.addr68_3, align 4
  br label %src.addr68.exit

src.addr68.exit:                                  ; preds = %src.addr68.case.3, %src.addr68.case.2, %src.addr68.case.1, %src.addr68.case.0
  %7 = phi float [ %_01, %src.addr68.case.0 ], [ %_12, %src.addr68.case.1 ], [ %_23, %src.addr68.case.2 ], [ %_34, %src.addr68.case.3 ]
  store float %7, float* %dst.addr57, align 4
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx39, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 43
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %src.addr68.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx10, 1
  %exitcond11 = icmp ne i64 %for.loop.idx.next, 4336
  br i1 %exitcond11, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_out([4336 x [43 x float]]* noalias "orig.arg.no"="0", [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4336 x i8]* noalias "orig.arg.no"="2", [4336 x i8]* noalias readonly "orig.arg.no"="3", [1082 x [43 x float]]* noalias "orig.arg.no"="4", [1082 x [43 x float]]* noalias readonly "orig.arg.no"="5", [1082 x i8]* noalias "orig.arg.no"="6", [1082 x i8]* noalias readonly align 512 "orig.arg.no"="7", [43 x float]* noalias "orig.arg.no"="8", [43 x float]* noalias readonly align 512 "orig.arg.no"="9", [43 x float]* noalias "orig.arg.no"="10", [43 x float]* noalias readonly align 512 "orig.arg.no"="11") #4 {
entry:
  call void @onebyonecpy_hls.p0a4336a43f32.85.86([4336 x [43 x float]]* %0, [1084 x [43 x float]]* %_0, [1084 x [43 x float]]* %_1, [1084 x [43 x float]]* %_2, [1084 x [43 x float]]* %_3)
  call fastcc void @onebyonecpy_hls.p0a4336i8([4336 x i8]* %1, [4336 x i8]* %2)
  call fastcc void @onebyonecpy_hls.p0a1082a43f32([1082 x [43 x float]]* %3, [1082 x [43 x float]]* %4)
  call fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* %5, [1082 x i8]* align 512 %6)
  call fastcc void @onebyonecpy_hls.p0a43f32([43 x float]* %7, [43 x float]* align 512 %8)
  call fastcc void @onebyonecpy_hls.p0a43f32([43 x float]* %9, [43 x float]* align 512 %10)
  ret void
}

declare void @apatb_kNN_PredictAll_hw([1084 x [43 x float]]*, [1084 x [43 x float]]*, [1084 x [43 x float]]*, [1084 x [43 x float]]*, i8*, [43 x float]*, i8*, float*, float*)

; Function Attrs: argmemonly noinline norecurse
define internal void @copy_back([4336 x [43 x float]]* noalias "orig.arg.no"="0", [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_0, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_1, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_2, [1084 x [43 x float]]* noalias readonly "fpga.caller.interfaces"="layout_transformed" "orig.arg.no"="1" %_3, [4336 x i8]* noalias "orig.arg.no"="2", [4336 x i8]* noalias readonly "orig.arg.no"="3", [1082 x [43 x float]]* noalias "orig.arg.no"="4", [1082 x [43 x float]]* noalias readonly "orig.arg.no"="5", [1082 x i8]* noalias "orig.arg.no"="6", [1082 x i8]* noalias readonly align 512 "orig.arg.no"="7", [43 x float]* noalias "orig.arg.no"="8", [43 x float]* noalias readonly align 512 "orig.arg.no"="9", [43 x float]* noalias "orig.arg.no"="10", [43 x float]* noalias readonly align 512 "orig.arg.no"="11") #4 {
entry:
  call fastcc void @onebyonecpy_hls.p0a1082a43f32([1082 x [43 x float]]* %3, [1082 x [43 x float]]* %4)
  call fastcc void @onebyonecpy_hls.p0a1082i8([1082 x i8]* %5, [1082 x i8]* align 512 %6)
  ret void
}

define void @kNN_PredictAll_hw_stub_wrapper([1084 x [43 x float]]*, [1084 x [43 x float]]*, [1084 x [43 x float]]*, [1084 x [43 x float]]*, i8*, [43 x float]*, i8*, float*, float*) #5 {
entry:
  %malloccall = tail call i8* @malloc(i64 745792)
  %9 = bitcast i8* %malloccall to [4336 x [43 x float]]*
  %10 = bitcast i8* %4 to [4336 x i8]*
  %11 = bitcast [43 x float]* %5 to [1082 x [43 x float]]*
  %12 = bitcast i8* %6 to [1082 x i8]*
  %13 = bitcast float* %7 to [43 x float]*
  %14 = bitcast float* %8 to [43 x float]*
  call void @copy_out([4336 x [43 x float]]* %9, [1084 x [43 x float]]* %0, [1084 x [43 x float]]* %1, [1084 x [43 x float]]* %2, [1084 x [43 x float]]* %3, [4336 x i8]* null, [4336 x i8]* %10, [1082 x [43 x float]]* null, [1082 x [43 x float]]* %11, [1082 x i8]* null, [1082 x i8]* %12, [43 x float]* null, [43 x float]* %13, [43 x float]* null, [43 x float]* %14)
  %15 = bitcast [4336 x [43 x float]]* %9 to [43 x float]*
  %16 = bitcast [4336 x i8]* %10 to i8*
  %17 = bitcast [1082 x [43 x float]]* %11 to [43 x float]*
  %18 = bitcast [1082 x i8]* %12 to i8*
  %19 = bitcast [43 x float]* %13 to float*
  %20 = bitcast [43 x float]* %14 to float*
  call void @kNN_PredictAll_hw_stub([43 x float]* %15, i8* %16, [43 x float]* %17, i8* %18, float* %19, float* %20)
  call void @copy_in([4336 x [43 x float]]* %9, [1084 x [43 x float]]* %0, [1084 x [43 x float]]* %1, [1084 x [43 x float]]* %2, [1084 x [43 x float]]* %3, [4336 x i8]* null, [4336 x i8]* %10, [1082 x [43 x float]]* null, [1082 x [43 x float]]* %11, [1082 x i8]* null, [1082 x i8]* %12, [43 x float]* null, [43 x float]* %13, [43 x float]* null, [43 x float]* %14)
  ret void
}

declare void @kNN_PredictAll_hw_stub([43 x float]*, i8*, [43 x float]*, i8*, float*, float*)

attributes #0 = { inaccessiblememonly nounwind }
attributes #1 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #2 = { argmemonly noinline norecurse "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyin" }
attributes #4 = { argmemonly noinline norecurse "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
!5 = !DILocation(line: 196, column: 9, scope: !6)
!6 = distinct !DILexicalBlock(scope: !8, file: !7, line: 195, column: 5)
!7 = !DIFile(filename: "knn/knn.cpp", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!8 = distinct !DILexicalBlock(scope: !9, file: !7, line: 194, column: 23)
!9 = distinct !DILexicalBlock(scope: !10, file: !7, line: 194, column: 23)
!10 = distinct !DISubprogram(name: "kNN_PredictAll", linkageName: "_Z14kNN_PredictAllPA43_fPcS0_S1_PfS2_", scope: !7, file: !7, line: 181, type: !11, isLocal: false, isDefinition: true, scopeLine: 186, flags: DIFlagPrototyped, isOptimized: false, unit: !21, variables: !4)
!11 = !DISubroutineType(types: !12)
!12 = !{null, !13, !18, !13, !18, !20, !20}
!13 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !14, size: 64)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !15, size: 1376, elements: !16)
!15 = !DIBasicType(name: "float", size: 32, encoding: DW_ATE_float)
!16 = !{!17}
!17 = !DISubrange(count: 43)
!18 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !19, size: 64)
!19 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!20 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !15, size: 64)
!21 = distinct !DICompileUnit(language: DW_LANG_C_plus_plus, file: !22, producer: "clang version 7.0.0 ", isOptimized: true, runtimeVersion: 0, emissionKind: FullDebug, enums: !4, retainedTypes: !23, imports: !25)
!22 = !DIFile(filename: "C:/Users/Tiago/Dev/Experiments/kNNChunkInstantiation/knn_vitis/solution1/.autopilot/db\5Cknn.pp.0.cpp", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!23 = !{!24, !19, !15}
!24 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!25 = !{!26, !33, !39, !41, !43, !47, !49, !51, !53, !55, !57, !59, !61, !66, !70, !72, !74, !79, !81, !83, !85, !87, !89, !91, !93, !95, !97, !101, !106, !108, !110, !112, !114, !116, !118, !120, !122, !124, !126, !130, !134, !136, !138, !140, !142, !144, !146, !148, !150, !152, !154, !156, !158, !160, !162, !164, !168, !172, !176, !178, !180, !182, !184, !186, !188, !190, !192, !194, !198, !202, !206, !208, !210, !212, !217, !221, !225, !227, !229, !231, !233, !235, !237, !239, !241, !243, !245, !247, !249, !254, !258, !262, !264, !266, !268, !274, !278, !282, !284, !286, !288, !290, !292, !294, !298, !302, !304, !306, !308, !310, !314, !318, !322, !324, !326, !328, !330, !332, !334, !338, !342, !346, !348, !352, !356, !358, !360, !362, !364, !366, !368, !373, !376, !378, !380, !382, !384, !386, !388, !390, !392, !394, !396, !398, !401, !404, !407, !410, !413, !415, !417, !419, !421, !423, !425, !427, !429, !431}
!26 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !28, file: !32, line: 52)
!27 = !DINamespace(name: "std", scope: null)
!28 = !DISubprogram(name: "abs", scope: !29, file: !29, line: 254, type: !30, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!29 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Cx86_64-w64-mingw32\5Cinclude\5Cmath.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!30 = !DISubroutineType(types: !31)
!31 = !{!24, !24}
!32 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Clib\5Cgcc\5Cx86_64-w64-mingw32\5C8.3.0\5Cinclude\5Cc++\5Cbits/std_abs.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!33 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !34, file: !38, line: 83)
!34 = !DISubprogram(name: "acos", scope: !29, file: !29, line: 190, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!35 = !DISubroutineType(types: !36)
!36 = !{!37, !37}
!37 = !DIBasicType(name: "double", size: 64, encoding: DW_ATE_float)
!38 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Clib\5Cgcc\5Cx86_64-w64-mingw32\5C8.3.0\5Cinclude\5Cc++\5Ccmath", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!39 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !40, file: !38, line: 102)
!40 = !DISubprogram(name: "asin", scope: !29, file: !29, line: 189, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!41 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !42, file: !38, line: 121)
!42 = !DISubprogram(name: "atan", scope: !29, file: !29, line: 191, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!43 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !44, file: !38, line: 140)
!44 = !DISubprogram(name: "atan2", scope: !29, file: !29, line: 192, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!45 = !DISubroutineType(types: !46)
!46 = !{!37, !37, !37}
!47 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !48, file: !38, line: 161)
!48 = !DISubprogram(name: "ceil", scope: !29, file: !29, line: 198, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!49 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !50, file: !38, line: 180)
!50 = !DISubprogram(name: "cos", scope: !29, file: !29, line: 184, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!51 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !52, file: !38, line: 199)
!52 = !DISubprogram(name: "cosh", scope: !29, file: !29, line: 187, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!53 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !54, file: !38, line: 218)
!54 = !DISubprogram(name: "exp", scope: !29, file: !29, line: 193, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!55 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !56, file: !38, line: 237)
!56 = !DISubprogram(name: "fabs", scope: !29, file: !29, line: 204, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!57 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !58, file: !38, line: 256)
!58 = !DISubprogram(name: "floor", scope: !29, file: !29, line: 199, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!59 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !60, file: !38, line: 275)
!60 = !DISubprogram(name: "fmod", scope: !29, file: !29, line: 246, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!61 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !62, file: !38, line: 296)
!62 = !DISubprogram(name: "frexp", scope: !29, file: !29, line: 244, type: !63, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!63 = !DISubroutineType(types: !64)
!64 = !{!37, !37, !65}
!65 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !24, size: 64)
!66 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !67, file: !38, line: 315)
!67 = !DISubprogram(name: "ldexp", scope: !29, file: !29, line: 243, type: !68, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!68 = !DISubroutineType(types: !69)
!69 = !{!37, !37, !24}
!70 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !71, file: !38, line: 334)
!71 = !DISubprogram(name: "log", scope: !29, file: !29, line: 194, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!72 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !73, file: !38, line: 353)
!73 = !DISubprogram(name: "log10", scope: !29, file: !29, line: 195, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!74 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !75, file: !38, line: 372)
!75 = !DISubprogram(name: "modf", scope: !29, file: !29, line: 245, type: !76, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!76 = !DISubroutineType(types: !77)
!77 = !{!37, !37, !78}
!78 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !37, size: 64)
!79 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !80, file: !38, line: 384)
!80 = !DISubprogram(name: "pow", scope: !29, file: !29, line: 196, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!81 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !82, file: !38, line: 421)
!82 = !DISubprogram(name: "sin", scope: !29, file: !29, line: 183, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!83 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !84, file: !38, line: 440)
!84 = !DISubprogram(name: "sinh", scope: !29, file: !29, line: 186, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!85 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !86, file: !38, line: 459)
!86 = !DISubprogram(name: "sqrt", scope: !29, file: !29, line: 197, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!87 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !88, file: !38, line: 478)
!88 = !DISubprogram(name: "tan", scope: !29, file: !29, line: 185, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!89 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !90, file: !38, line: 497)
!90 = !DISubprogram(name: "tanh", scope: !29, file: !29, line: 188, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!91 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !92, file: !38, line: 1065)
!92 = !DIDerivedType(tag: DW_TAG_typedef, name: "double_t", file: !29, line: 373, baseType: !37)
!93 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !94, file: !38, line: 1066)
!94 = !DIDerivedType(tag: DW_TAG_typedef, name: "float_t", file: !29, line: 372, baseType: !15)
!95 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !96, file: !38, line: 1069)
!96 = !DISubprogram(name: "acosh", scope: !29, file: !29, line: 705, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!97 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !98, file: !38, line: 1070)
!98 = !DISubprogram(name: "acoshf", scope: !29, file: !29, line: 706, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!99 = !DISubroutineType(types: !100)
!100 = !{!15, !15}
!101 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !102, file: !38, line: 1071)
!102 = !DISubprogram(name: "acoshl", scope: !29, file: !29, line: 707, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!103 = !DISubroutineType(types: !104)
!104 = !{!105, !105}
!105 = !DIBasicType(name: "long double", size: 64, encoding: DW_ATE_float)
!106 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !107, file: !38, line: 1073)
!107 = !DISubprogram(name: "asinh", scope: !29, file: !29, line: 710, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!108 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !109, file: !38, line: 1074)
!109 = !DISubprogram(name: "asinhf", scope: !29, file: !29, line: 711, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!110 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !111, file: !38, line: 1075)
!111 = !DISubprogram(name: "asinhl", scope: !29, file: !29, line: 712, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!112 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !113, file: !38, line: 1077)
!113 = !DISubprogram(name: "atanh", scope: !29, file: !29, line: 715, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!114 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !115, file: !38, line: 1078)
!115 = !DISubprogram(name: "atanhf", scope: !29, file: !29, line: 716, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!116 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !117, file: !38, line: 1079)
!117 = !DISubprogram(name: "atanhl", scope: !29, file: !29, line: 717, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!118 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !119, file: !38, line: 1081)
!119 = !DISubprogram(name: "cbrt", scope: !29, file: !29, line: 877, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!120 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !121, file: !38, line: 1082)
!121 = !DISubprogram(name: "cbrtf", scope: !29, file: !29, line: 878, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!122 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !123, file: !38, line: 1083)
!123 = !DISubprogram(name: "cbrtl", scope: !29, file: !29, line: 879, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!124 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !125, file: !38, line: 1085)
!125 = !DISubprogram(name: "copysign", scope: !29, file: !29, line: 1063, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!126 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !127, file: !38, line: 1086)
!127 = !DISubprogram(name: "copysignf", scope: !29, file: !29, line: 1064, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!128 = !DISubroutineType(types: !129)
!129 = !{!15, !15, !15}
!130 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !131, file: !38, line: 1087)
!131 = !DISubprogram(name: "copysignl", scope: !29, file: !29, line: 1065, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!132 = !DISubroutineType(types: !133)
!133 = !{!105, !105, !105}
!134 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !135, file: !38, line: 1089)
!135 = !DISubprogram(name: "erf", scope: !29, file: !29, line: 901, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!136 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !137, file: !38, line: 1090)
!137 = !DISubprogram(name: "erff", scope: !29, file: !29, line: 902, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!138 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !139, file: !38, line: 1091)
!139 = !DISubprogram(name: "erfl", scope: !29, file: !29, line: 903, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!140 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !141, file: !38, line: 1093)
!141 = !DISubprogram(name: "erfc", scope: !29, file: !29, line: 906, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!142 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !143, file: !38, line: 1094)
!143 = !DISubprogram(name: "erfcf", scope: !29, file: !29, line: 907, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!144 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !145, file: !38, line: 1095)
!145 = !DISubprogram(name: "erfcl", scope: !29, file: !29, line: 908, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!146 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !147, file: !38, line: 1097)
!147 = !DISubprogram(name: "exp2", scope: !29, file: !29, line: 728, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!148 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !149, file: !38, line: 1098)
!149 = !DISubprogram(name: "exp2f", scope: !29, file: !29, line: 729, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!150 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !151, file: !38, line: 1099)
!151 = !DISubprogram(name: "exp2l", scope: !29, file: !29, line: 730, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!152 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !153, file: !38, line: 1101)
!153 = !DISubprogram(name: "expm1", scope: !29, file: !29, line: 734, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!154 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !155, file: !38, line: 1102)
!155 = !DISubprogram(name: "expm1f", scope: !29, file: !29, line: 735, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!156 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !157, file: !38, line: 1103)
!157 = !DISubprogram(name: "expm1l", scope: !29, file: !29, line: 736, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!158 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !159, file: !38, line: 1105)
!159 = !DISubprogram(name: "fdim", scope: !29, file: !29, line: 1109, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!160 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !161, file: !38, line: 1106)
!161 = !DISubprogram(name: "fdimf", scope: !29, file: !29, line: 1110, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!162 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !163, file: !38, line: 1107)
!163 = !DISubprogram(name: "fdiml", scope: !29, file: !29, line: 1111, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!164 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !165, file: !38, line: 1109)
!165 = !DISubprogram(name: "fma", scope: !29, file: !29, line: 1130, type: !166, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!166 = !DISubroutineType(types: !167)
!167 = !{!37, !37, !37, !37}
!168 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !169, file: !38, line: 1110)
!169 = !DISubprogram(name: "fmaf", scope: !29, file: !29, line: 1131, type: !170, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!170 = !DISubroutineType(types: !171)
!171 = !{!15, !15, !15, !15}
!172 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !173, file: !38, line: 1111)
!173 = !DISubprogram(name: "fmal", scope: !29, file: !29, line: 1132, type: !174, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!174 = !DISubroutineType(types: !175)
!175 = !{!105, !105, !105, !105}
!176 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !177, file: !38, line: 1113)
!177 = !DISubprogram(name: "fmax", scope: !29, file: !29, line: 1119, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!178 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !179, file: !38, line: 1114)
!179 = !DISubprogram(name: "fmaxf", scope: !29, file: !29, line: 1120, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!180 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !181, file: !38, line: 1115)
!181 = !DISubprogram(name: "fmaxl", scope: !29, file: !29, line: 1121, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!182 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !183, file: !38, line: 1117)
!183 = !DISubprogram(name: "fmin", scope: !29, file: !29, line: 1124, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!184 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !185, file: !38, line: 1118)
!185 = !DISubprogram(name: "fminf", scope: !29, file: !29, line: 1125, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!186 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !187, file: !38, line: 1119)
!187 = !DISubprogram(name: "fminl", scope: !29, file: !29, line: 1126, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!188 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !189, file: !38, line: 1121)
!189 = !DISubprogram(name: "hypot", scope: !29, file: !29, line: 882, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!190 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !191, file: !38, line: 1122)
!191 = !DISubprogram(name: "hypotf", scope: !29, file: !29, line: 883, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!192 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !193, file: !38, line: 1123)
!193 = !DISubprogram(name: "hypotl", scope: !29, file: !29, line: 887, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!194 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !195, file: !38, line: 1125)
!195 = !DISubprogram(name: "ilogb", scope: !29, file: !29, line: 748, type: !196, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!196 = !DISubroutineType(types: !197)
!197 = !{!24, !37}
!198 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !199, file: !38, line: 1126)
!199 = !DISubprogram(name: "ilogbf", scope: !29, file: !29, line: 749, type: !200, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!200 = !DISubroutineType(types: !201)
!201 = !{!24, !15}
!202 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !203, file: !38, line: 1127)
!203 = !DISubprogram(name: "ilogbl", scope: !29, file: !29, line: 750, type: !204, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!204 = !DISubroutineType(types: !205)
!205 = !{!24, !105}
!206 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !207, file: !38, line: 1129)
!207 = !DISubprogram(name: "lgamma", scope: !29, file: !29, line: 911, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!208 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !209, file: !38, line: 1130)
!209 = !DISubprogram(name: "lgammaf", scope: !29, file: !29, line: 912, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!210 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !211, file: !38, line: 1131)
!211 = !DISubprogram(name: "lgammal", scope: !29, file: !29, line: 913, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!212 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !213, file: !38, line: 1134)
!213 = !DISubprogram(name: "llrint", scope: !29, file: !29, line: 946, type: !214, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!214 = !DISubroutineType(types: !215)
!215 = !{!216, !37}
!216 = !DIBasicType(name: "long long int", size: 64, encoding: DW_ATE_signed)
!217 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !218, file: !38, line: 1135)
!218 = !DISubprogram(name: "llrintf", scope: !29, file: !29, line: 947, type: !219, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!219 = !DISubroutineType(types: !220)
!220 = !{!216, !15}
!221 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !222, file: !38, line: 1136)
!222 = !DISubprogram(name: "llrintl", scope: !29, file: !29, line: 948, type: !223, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!223 = !DISubroutineType(types: !224)
!224 = !{!216, !105}
!225 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !226, file: !38, line: 1138)
!226 = !DISubprogram(name: "llround", scope: !29, file: !29, line: 1038, type: !214, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!227 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !228, file: !38, line: 1139)
!228 = !DISubprogram(name: "llroundf", scope: !29, file: !29, line: 1039, type: !219, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!229 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !230, file: !38, line: 1140)
!230 = !DISubprogram(name: "llroundl", scope: !29, file: !29, line: 1040, type: !223, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!231 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !232, file: !38, line: 1143)
!232 = !DISubprogram(name: "log1p", scope: !29, file: !29, line: 768, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!233 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !234, file: !38, line: 1144)
!234 = !DISubprogram(name: "log1pf", scope: !29, file: !29, line: 769, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!235 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !236, file: !38, line: 1145)
!236 = !DISubprogram(name: "log1pl", scope: !29, file: !29, line: 770, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!237 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !238, file: !38, line: 1147)
!238 = !DISubprogram(name: "log2", scope: !29, file: !29, line: 773, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!239 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !240, file: !38, line: 1148)
!240 = !DISubprogram(name: "log2f", scope: !29, file: !29, line: 774, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!241 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !242, file: !38, line: 1149)
!242 = !DISubprogram(name: "log2l", scope: !29, file: !29, line: 775, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!243 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !244, file: !38, line: 1151)
!244 = !DISubprogram(name: "logb", scope: !29, file: !29, line: 778, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!245 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !246, file: !38, line: 1152)
!246 = !DISubprogram(name: "logbf", scope: !29, file: !29, line: 779, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!247 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !248, file: !38, line: 1153)
!248 = !DISubprogram(name: "logbl", scope: !29, file: !29, line: 780, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!249 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !250, file: !38, line: 1155)
!250 = !DISubprogram(name: "lrint", scope: !29, file: !29, line: 942, type: !251, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!251 = !DISubroutineType(types: !252)
!252 = !{!253, !37}
!253 = !DIBasicType(name: "long int", size: 64, encoding: DW_ATE_signed)
!254 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !255, file: !38, line: 1156)
!255 = !DISubprogram(name: "lrintf", scope: !29, file: !29, line: 943, type: !256, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!256 = !DISubroutineType(types: !257)
!257 = !{!253, !15}
!258 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !259, file: !38, line: 1157)
!259 = !DISubprogram(name: "lrintl", scope: !29, file: !29, line: 944, type: !260, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!260 = !DISubroutineType(types: !261)
!261 = !{!253, !105}
!262 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !263, file: !38, line: 1159)
!263 = !DISubprogram(name: "lround", scope: !29, file: !29, line: 1035, type: !251, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!264 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !265, file: !38, line: 1160)
!265 = !DISubprogram(name: "lroundf", scope: !29, file: !29, line: 1036, type: !256, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!266 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !267, file: !38, line: 1161)
!267 = !DISubprogram(name: "lroundl", scope: !29, file: !29, line: 1037, type: !260, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!268 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !269, file: !38, line: 1163)
!269 = !DISubprogram(name: "nan", scope: !29, file: !29, line: 1087, type: !270, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!270 = !DISubroutineType(types: !271)
!271 = !{!37, !272}
!272 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !273, size: 64)
!273 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !19)
!274 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !275, file: !38, line: 1164)
!275 = !DISubprogram(name: "nanf", scope: !29, file: !29, line: 1088, type: !276, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!276 = !DISubroutineType(types: !277)
!277 = !{!15, !272}
!278 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !279, file: !38, line: 1165)
!279 = !DISubprogram(name: "nanl", scope: !29, file: !29, line: 1089, type: !280, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!280 = !DISubroutineType(types: !281)
!281 = !{!105, !272}
!282 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !283, file: !38, line: 1167)
!283 = !DISubprogram(name: "nearbyint", scope: !29, file: !29, line: 931, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!284 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !285, file: !38, line: 1168)
!285 = !DISubprogram(name: "nearbyintf", scope: !29, file: !29, line: 932, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!286 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !287, file: !38, line: 1169)
!287 = !DISubprogram(name: "nearbyintl", scope: !29, file: !29, line: 933, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!288 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !289, file: !38, line: 1171)
!289 = !DISubprogram(name: "nextafter", scope: !29, file: !29, line: 1098, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!290 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !291, file: !38, line: 1172)
!291 = !DISubprogram(name: "nextafterf", scope: !29, file: !29, line: 1099, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!292 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !293, file: !38, line: 1173)
!293 = !DISubprogram(name: "nextafterl", scope: !29, file: !29, line: 1100, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!294 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !295, file: !38, line: 1175)
!295 = !DISubprogram(name: "nexttoward", scope: !29, file: !29, line: 1103, type: !296, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!296 = !DISubroutineType(types: !297)
!297 = !{!37, !37, !105}
!298 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !299, file: !38, line: 1176)
!299 = !DISubprogram(name: "nexttowardf", scope: !29, file: !29, line: 1104, type: !300, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!300 = !DISubroutineType(types: !301)
!301 = !{!15, !15, !105}
!302 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !303, file: !38, line: 1177)
!303 = !DISubprogram(name: "nexttowardl", scope: !29, file: !29, line: 1105, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!304 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !305, file: !38, line: 1179)
!305 = !DISubprogram(name: "remainder", scope: !29, file: !29, line: 1053, type: !45, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!306 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !307, file: !38, line: 1180)
!307 = !DISubprogram(name: "remainderf", scope: !29, file: !29, line: 1054, type: !128, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!308 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !309, file: !38, line: 1181)
!309 = !DISubprogram(name: "remainderl", scope: !29, file: !29, line: 1055, type: !132, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!310 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !311, file: !38, line: 1183)
!311 = !DISubprogram(name: "remquo", scope: !29, file: !29, line: 1058, type: !312, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!312 = !DISubroutineType(types: !313)
!313 = !{!37, !37, !37, !65}
!314 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !315, file: !38, line: 1184)
!315 = !DISubprogram(name: "remquof", scope: !29, file: !29, line: 1059, type: !316, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!316 = !DISubroutineType(types: !317)
!317 = !{!15, !15, !15, !65}
!318 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !319, file: !38, line: 1185)
!319 = !DISubprogram(name: "remquol", scope: !29, file: !29, line: 1060, type: !320, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!320 = !DISubroutineType(types: !321)
!321 = !{!105, !105, !105, !65}
!322 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !323, file: !38, line: 1187)
!323 = !DISubprogram(name: "rint", scope: !29, file: !29, line: 937, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!324 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !325, file: !38, line: 1188)
!325 = !DISubprogram(name: "rintf", scope: !29, file: !29, line: 938, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!326 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !327, file: !38, line: 1189)
!327 = !DISubprogram(name: "rintl", scope: !29, file: !29, line: 939, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!328 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !329, file: !38, line: 1191)
!329 = !DISubprogram(name: "round", scope: !29, file: !29, line: 1030, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!330 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !331, file: !38, line: 1192)
!331 = !DISubprogram(name: "roundf", scope: !29, file: !29, line: 1031, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!332 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !333, file: !38, line: 1193)
!333 = !DISubprogram(name: "roundl", scope: !29, file: !29, line: 1032, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!334 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !335, file: !38, line: 1195)
!335 = !DISubprogram(name: "scalbln", scope: !29, file: !29, line: 871, type: !336, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!336 = !DISubroutineType(types: !337)
!337 = !{!37, !37, !253}
!338 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !339, file: !38, line: 1196)
!339 = !DISubprogram(name: "scalblnf", scope: !29, file: !29, line: 872, type: !340, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!340 = !DISubroutineType(types: !341)
!341 = !{!15, !15, !253}
!342 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !343, file: !38, line: 1197)
!343 = !DISubprogram(name: "scalblnl", scope: !29, file: !29, line: 873, type: !344, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!344 = !DISubroutineType(types: !345)
!345 = !{!105, !105, !253}
!346 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !347, file: !38, line: 1199)
!347 = !DISubprogram(name: "scalbn", scope: !29, file: !29, line: 867, type: !68, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!348 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !349, file: !38, line: 1200)
!349 = !DISubprogram(name: "scalbnf", scope: !29, file: !29, line: 868, type: !350, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!350 = !DISubroutineType(types: !351)
!351 = !{!15, !15, !24}
!352 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !353, file: !38, line: 1201)
!353 = !DISubprogram(name: "scalbnl", scope: !29, file: !29, line: 869, type: !354, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!354 = !DISubroutineType(types: !355)
!355 = !{!105, !105, !24}
!356 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !357, file: !38, line: 1203)
!357 = !DISubprogram(name: "tgamma", scope: !29, file: !29, line: 918, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!358 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !359, file: !38, line: 1204)
!359 = !DISubprogram(name: "tgammaf", scope: !29, file: !29, line: 919, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!360 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !361, file: !38, line: 1205)
!361 = !DISubprogram(name: "tgammal", scope: !29, file: !29, line: 920, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!362 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !363, file: !38, line: 1207)
!363 = !DISubprogram(name: "trunc", scope: !29, file: !29, line: 1044, type: !35, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!364 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !365, file: !38, line: 1208)
!365 = !DISubprogram(name: "truncf", scope: !29, file: !29, line: 1045, type: !99, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!366 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !367, file: !38, line: 1209)
!367 = !DISubprogram(name: "truncl", scope: !29, file: !29, line: 1046, type: !103, isLocal: false, isDefinition: false, flags: DIFlagPrototyped, isOptimized: false)
!368 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !369, file: !372, line: 48)
!369 = !DIDerivedType(tag: DW_TAG_typedef, name: "int8_t", file: !370, line: 35, baseType: !371)
!370 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Cx86_64-w64-mingw32\5Cinclude\5Cstdint.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!371 = !DIBasicType(name: "signed char", size: 8, encoding: DW_ATE_signed_char)
!372 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Clib\5Cgcc\5Cx86_64-w64-mingw32\5C8.3.0\5Cinclude\5Cc++\5Ccstdint", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!373 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !374, file: !372, line: 49)
!374 = !DIDerivedType(tag: DW_TAG_typedef, name: "int16_t", file: !370, line: 37, baseType: !375)
!375 = !DIBasicType(name: "short", size: 16, encoding: DW_ATE_signed)
!376 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !377, file: !372, line: 50)
!377 = !DIDerivedType(tag: DW_TAG_typedef, name: "int32_t", file: !370, line: 39, baseType: !24)
!378 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !379, file: !372, line: 51)
!379 = !DIDerivedType(tag: DW_TAG_typedef, name: "int64_t", file: !370, line: 41, baseType: !216)
!380 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !381, file: !372, line: 53)
!381 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast8_t", file: !370, line: 58, baseType: !371)
!382 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !383, file: !372, line: 54)
!383 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast16_t", file: !370, line: 60, baseType: !375)
!384 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !385, file: !372, line: 55)
!385 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast32_t", file: !370, line: 62, baseType: !24)
!386 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !387, file: !372, line: 56)
!387 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_fast64_t", file: !370, line: 64, baseType: !216)
!388 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !389, file: !372, line: 58)
!389 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least8_t", file: !370, line: 45, baseType: !371)
!390 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !391, file: !372, line: 59)
!391 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least16_t", file: !370, line: 47, baseType: !375)
!392 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !393, file: !372, line: 60)
!393 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least32_t", file: !370, line: 49, baseType: !24)
!394 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !395, file: !372, line: 61)
!395 = !DIDerivedType(tag: DW_TAG_typedef, name: "int_least64_t", file: !370, line: 51, baseType: !216)
!396 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !397, file: !372, line: 63)
!397 = !DIDerivedType(tag: DW_TAG_typedef, name: "intmax_t", file: !370, line: 68, baseType: !216)
!398 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !399, file: !372, line: 64)
!399 = !DIDerivedType(tag: DW_TAG_typedef, name: "intptr_t", file: !400, line: 62, baseType: !253)
!400 = !DIFile(filename: "E:/Xilinx/Vitis_HLS/2022.1/tps/mingw/8.3.0/win64.o/nt\5Cx86_64-w64-mingw32\5Cinclude\5Ccrtdefs.h", directory: "C:\5CUsers\5CTiago\5CDev\5CExperiments\5CkNNChunkInstantiation")
!401 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !402, file: !372, line: 66)
!402 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint8_t", file: !370, line: 36, baseType: !403)
!403 = !DIBasicType(name: "unsigned char", size: 8, encoding: DW_ATE_unsigned_char)
!404 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !405, file: !372, line: 67)
!405 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint16_t", file: !370, line: 38, baseType: !406)
!406 = !DIBasicType(name: "unsigned short", size: 16, encoding: DW_ATE_unsigned)
!407 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !408, file: !372, line: 68)
!408 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint32_t", file: !370, line: 40, baseType: !409)
!409 = !DIBasicType(name: "unsigned int", size: 32, encoding: DW_ATE_unsigned)
!410 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !411, file: !372, line: 69)
!411 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint64_t", file: !370, line: 42, baseType: !412)
!412 = !DIBasicType(name: "long long unsigned int", size: 64, encoding: DW_ATE_unsigned)
!413 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !414, file: !372, line: 71)
!414 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast8_t", file: !370, line: 59, baseType: !403)
!415 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !416, file: !372, line: 72)
!416 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast16_t", file: !370, line: 61, baseType: !406)
!417 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !418, file: !372, line: 73)
!418 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast32_t", file: !370, line: 63, baseType: !409)
!419 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !420, file: !372, line: 74)
!420 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_fast64_t", file: !370, line: 65, baseType: !412)
!421 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !422, file: !372, line: 76)
!422 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least8_t", file: !370, line: 46, baseType: !403)
!423 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !424, file: !372, line: 77)
!424 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least16_t", file: !370, line: 48, baseType: !406)
!425 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !426, file: !372, line: 78)
!426 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least32_t", file: !370, line: 50, baseType: !409)
!427 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !428, file: !372, line: 79)
!428 = !DIDerivedType(tag: DW_TAG_typedef, name: "uint_least64_t", file: !370, line: 52, baseType: !412)
!429 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !430, file: !372, line: 81)
!430 = !DIDerivedType(tag: DW_TAG_typedef, name: "uintmax_t", file: !370, line: 69, baseType: !412)
!431 = !DIImportedEntity(tag: DW_TAG_imported_declaration, scope: !27, entity: !432, file: !372, line: 82)
!432 = !DIDerivedType(tag: DW_TAG_typedef, name: "uintptr_t", file: !400, line: 75, baseType: !433)
!433 = !DIBasicType(name: "long unsigned int", size: 64, encoding: DW_ATE_unsigned)
